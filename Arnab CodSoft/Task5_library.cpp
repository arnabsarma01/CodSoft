#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool checkedOut;
};

void searchBooks(const vector<Book>& books, const string& query) {
    cout << "Search Results:\n";
    for (const Book& book : books) {
        if (book.title.find(query) != string::npos ||
            book.author.find(query) != string::npos ||
            book.ISBN == query) {
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "ISBN: " << book.ISBN << "\n";
            cout << "Status: " << (book.checkedOut ? "Checked out" : "Available") << "\n";
            cout << "-------------------\n";
        }
    }
}

void checkoutBook(vector<Book>& books, const string& ISBN) {
    for (Book& book : books) {
        if (book.ISBN == ISBN && !book.checkedOut) {
            book.checkedOut = true;
            cout << "Book with ISBN " << ISBN << " is checked out.\n";
            return;
        }
    }
    cout << "Book not found or already checked out.\n";
}

void returnBook(vector<Book>& books, const string& ISBN) {
    for (Book& book : books) {
        if (book.ISBN == ISBN && book.checkedOut) {
            book.checkedOut = false;
            cout << "Book with ISBN " << ISBN << " is returned.\n";
            return;
        }
    }
    cout << "Book not found or not checked out.\n";
}

int main() {
    vector<Book> library;

    library.push_back({"ABC", "Author 1", "123456", false});
    library.push_back({"DEF", "Author 2", "234567", false});
    library.push_back({"GHI", "Author 3", "345678", false});

    while (true) {
        cout << "Library Management System Menu:\n";
        cout << "1. Search for a book\n";
        cout << "2. Checkout a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter a title, author, or ISBN to search: ";
                string query;
                cin >> query;
                searchBooks(library, query);
                break;
            }
            case 2: {
                cout << "Enter the ISBN of the book you want to checkout: ";
                string ISBN;
                cin >> ISBN;
                checkoutBook(library, ISBN);
                break;
            }
            case 3: {
                cout << "Enter the ISBN of the book you want to return: ";
                string ISBN;
                cin >> ISBN;
                returnBook(library, ISBN);
                break;
            }
            case 4: {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
