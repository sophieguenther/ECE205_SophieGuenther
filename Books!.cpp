#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Book {
private:
    string title;
    int year;
    string author;

public:
    // Constructor
    Book(string t, int y, string a) {
        title = t;
        year = y;
        author = a;
    }

    // Accessors
    string getTitle() {
        return title;
    }

    int getYear() {
        return year;
    }

    string getAuthor() {
        return author;
    }

    // Display book info
    void display() {
        cout << "Title: " << title
             << ", Year: " << year
             << ", Author: " << author << endl;
    }
};

// Function to display books alphabetically by author 
void displaySorted(vector<Book>& books) {
    sort(books.begin(), books.end(),
        [](Book a, Book b) {
            return a.getAuthor() < b.getAuthor();
        });

    cout << "\nBooks Sorted by Author:\n";

    for (Book b : books) {
        b.display();
    }
}

// Remove book by title (assuming title is unique)
void removeBook(vector<Book>& books, string title) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            books.erase(books.begin() + i);
            cout << "Book removed.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

int main() {
    vector<Book> books;

    int choice;

    do {
        cout << "\n===== BOOK DATABASE =====\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books Sorted by Author\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            int year;

            cin.ignore();

            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter year: ";
            cin >> year;

            cin.ignore();

            cout << "Enter author: ";
            getline(cin, author);

            books.push_back(Book(title, year, author));

            cout << "Book added.\n";
        }

        else if (choice == 2) {
            string title;

            cin.ignore();

            cout << "Enter title to remove: ";
            getline(cin, title);

            removeBook(books, title);
        }

        else if (choice == 3) {
            displaySorted(books);
        }

        else if (choice == 4) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}