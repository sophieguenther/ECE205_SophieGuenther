#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string val, Node* l = nullptr, Node* r = nullptr) { //left and right nodes for branches 
        data = val;
        left = l;
        right = r;
    }

    bool isOperator() {// is it an operator
        return (data == "+" || data == "-" ||
                data == "*" || data == "/" ||
                data == "^");
    }
};
int precedence(char op) { //pemdas 
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {//take in string and make it postfix with spaces for readability
    stack<char> opStack;//stack of operatiors
    string postfix;
    for (int i =0; i <infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue; // skip spaces
        if (isdigit(c)) {//is it a digit
            postfix += c;
            while (i + 1 < infix.length() && isdigit(infix[i + 1])) { //is it two+ digits 
                postfix += infix[++i];
            }
            postfix += ' '; //space
        }

        else if (c == '(') { //is it an open parenthesis
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        }

        else { // operator
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {//stack is not empty and precedence is greater than or equal to current operator (pemdas stuff)
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }
    return postfix;
}

//make tree
Node* constructTree(string postfix) {
    stack<Node*> st;//make node stack 

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (c == ' ') continue;

        // many digit num
        if (isdigit(c)) {
            string num = "";
            while (i < postfix.length() && postfix[i] != ' ') {
                num += postfix[i++];
            }
            st.push(new Node(num));
        }

        else { // operator
            Node* right = st.top(); st.pop(); // right branch is the top of the stack, then pop it off
            Node* left = st.top(); st.pop();// left branch is the next top of the stack, then pop it off

            Node* newNode = new Node(string(1, c), left, right);// make new node with operator and left and right branches
            st.push(newNode);
        }
    }
    return st.top();
}


void postorder(Node* root, string& output) { //go backwards and add spaces 
    if (!root) return;
    postorder(root->left, output);
    postorder(root->right, output);
    output += root->data + " ";
}

int evaluateTree(Node* root) { // evaluate the tree recursively, if its an operator evaluate left and right branches, if its a number return the number
    if (!root) return 0;//if its num
    if (!root->isOperator()) {
        return stoi(root->data);//string to int
    }
    int leftVal = evaluateTree(root->left);
    int rightVal = evaluateTree(root->right);
    //branches
    if (root->data == "+") return leftVal + rightVal;// if its an operator, do the operation on the left and right branches
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;
    if (root->data == "/") {
    if (rightVal == 0) {
        cout << "can not divide by zero" << endl;
        return 0;
        }
        return leftVal / rightVal;
    }
    if (root->data == "^") return pow(leftVal, rightVal);

    return 0;
}
//delete tree so uou can replay
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string infix;
    char replay = 'y';

    while (replay == 'y' || replay == 'Y') {

        cout << "enter infix expression (space separated)-> ";
        getline(cin, infix);// get the whole line of input, including spaces, for the infix expression
        string postfix = infixToPostfix(infix);
        cout << "postfix: " << postfix << endl;

        Node* root = constructTree(postfix);

        string postorderResult = "";
        postorder(root, postorderResult);

        int result = evaluateTree(root);
        cout << "Result: " << result << endl;
        deleteTree(root);//wipe memory
        cout << "would you like to replay? (y/n): ";
        cin >> replay;
        cin.ignore();
    }

    return 0;
}
