#include<iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool isAvailable;

    Book(string _title, string _author, int _id) {
        title = _title;
        author = _author;
        id = _id;
        isAvailable = true;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int id) {
        Book newBook(title, author, id);
        books.push_back(newBook);
    }

    void displayBooks() {
        for (const Book &book : books) {
            cout << "ID: " << book.id << " Title: " << book.title << " Author: " << book.author << " Status: " << (book.isAvailable ? "Available" : "Not Available") << endl;
        }
    }

    Book* findBook(int id) {
        for (Book &book : books) {
            if (book.id == id) {
                return &book;
            }
        }
        return nullptr;
    }

    void checkOutBook(int id) {
        Book* book = findBook(id);
        if (book != nullptr) {
            if (book->isAvailable) {
                book->isAvailable = false;
                cout << "Book " << book->title << " is checked out." << endl;
            } else {
                cout << "Book " << book->title << " is not available." << endl;
            }
        } else {
            cout << "Book not found." << endl;
        }
    }

    void checkInBook(int id) {
        Book* book = findBook(id);
        if (book != nullptr) {
            if (!book->isAvailable) {
                book->isAvailable = true;
                cout << "Book " << book->title << " is checked in." << endl;
            } else {
                cout << "Book " << book->title << " is already available." << endl;
            }
        } else {
            cout << "Book not found." << endl;
        }
    }

};

int main() {
    Library library;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Check Out Book\n";
        cout << "4. Check In Book\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int id;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter book ID: ";
                cin >> id;
                library.addBook(title, author, id);
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                int id;
                cout << "Enter book ID to check out: ";
                cin >> id;
                library.checkOutBook(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter book ID to check in: ";
                cin >> id;
                library.checkInBook(id);
                break;
            }
            case 5:{
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
