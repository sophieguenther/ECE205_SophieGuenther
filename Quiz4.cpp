/*
Define a class called Book which is an abstract data type for searching a book from a history bookstore. You will search the book by category, publishing year, and ISBN. The book category should be a string, publishing year and ISBN should be an integer type. The book will only be available in the store if the book was published after the year 1950 and the category is “history” for any ISBN value. Display the output if the book is available or not. You will take the input from the console. 

Include all the following specifications: 

1)	Make all member variables private.
2)	a constructor to set the book selecting parameters as an argument.  
3)	A non-member output (display) function that outputs the availability. 
4)	Other member/non-member functions if you need them. 


*/
#include <iostream>
using namespace std;

class Book{
    private:
        string BookCategory;
        int PublishYear;
        int ISBN;
        bool available;
    public:
        //constructor
        Book(string category, int year, int isbn){
            BookCategory=category;
            PublishYear=year;
            ISBN=isbn;
        }
        //getter functions
        string getCategory(){
            return BookCategory;
        }
        int getYear(){
            return PublishYear;
        }
        int getISBN(){
            return ISBN;
        }
        //function to check if the book is available
        bool isAvailable(){
            if ((BookCategory=="history" || BookCategory=="History") && PublishYear>1950){
                return true;
            }
            else{
                return false;
            }
        }
        void display(){
            if (isAvailable()){
                cout << "The book is available in the store." << endl;
            }
            else{
                cout << "The book is not available in the store." << endl;
            }
        }
};

int main(){
    string category;
    int year;
    int isbn;
    cout << "Enter the book category: -> ";
    cin >> category;
    cout << "Enter the publishing year: -> ";
    cin >> year;
    cout << "Enter the ISBN number: -> ";
    cin >> isbn;
    Book book1(category, year, isbn);
    book1.display();
    return 0;
}