//homework 6.2 write void fcn that deletes repeated characters 

#include <iostream>
#include <vector>

using namespace std;
void deleteRepeatedChars(vector<char>& myVector) {
    for(int i=0; i<myVector.size(); i++){
        for(int j=i+1; j<myVector.size(); j++){
            if(myVector[i] == myVector[j]){
                myVector.erase(myVector.begin() + j); // remove the duplicate character (found this in textbook section)
                j--; // fix index after erasing
            }
        }
    }


}
//swaps values based on the index in selection sort
void swapValues(vector<char>& myVector, int i, int j){
    char temp = myVector[i];
    myVector[i] = myVector[j];
    myVector[j] = temp;
}
//z to a
void selectionSort(vector<char>& myVector){
    //have to make characters in digits to sort them, then convert back to characters
    int n = myVector.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        // find the largest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (myVector[j] > myVector[maxIndex]) {
                maxIndex = j;
            }
        }

        // swap into correct position
        swapValues(myVector, i, maxIndex);
    }
}


int main(){
    vector<char> myVector;
    char input;
    char replay= 'y';
    while(replay == 'y' || replay == 'Y'){

        cout << "Enter characters (enter 0to stop): ";
        cin >> input;
        while (input != '0') {
            myVector.push_back(input);
            cin >> input;
        }
    
        deleteRepeatedChars(myVector);
        selectionSort(myVector);

        cout << "Unique characters in sorted order: ";
        for (char c : myVector) {//for each character in vector, print out the char
            cout << c << " ";
        }
        cout << endl;
        cout << "Do you want to enter more characters? (y/n): ";
        cin >> replay;
        myVector.clear(); // clear the vector for the next input
    }
    return 0;
}
