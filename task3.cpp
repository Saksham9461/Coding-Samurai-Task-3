//C++ program for library management system
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class for book details
class Book {
public:
    Book(int id, string author,string title ) : id(id), author(author),title(title) , available(true) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getId() const {
        return id;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool availability) {
        available = availability;
    }



private:
    string title;
    string author;
    int id;
    bool available;
};


//class for adding book,removing book,display catalog,checkavailability,checkout book,return book
class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        auto it = remove_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getId() == id;
        });

        books.erase(it, books.end());
    }

    void displayCatalog() const {
        cout << "Library Catalog:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                      << ", Availability: " << (book.isAvailable() ? "Available" : "Checked Out") << "\n";
        }
    }

    bool checkAvailability(int id) const {
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getId() == id;
        });

        return it != books.end() && it->isAvailable();
    }

    void checkoutBook(int id) {
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getId() == id;
        });

        if (it != books.end() && it->isAvailable()) {
            it->setAvailability(false);
            cout << "Book checked out successfully.\n";
        } else {
            cout << "Book not found or not available for checkout.\n";
        }
    }

    void returnBook(int id) {
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getId() == id;
        });

        if (it != books.end() && !it->isAvailable()) {
            it->setAvailability(true);
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book not found or already available.\n";
        }
    }

private:
    vector<Book> books;
};

int main() {
    Library library;
//book details that contain id of book,author of book,title of book
    Book book1(101, "J.D. Salinger", "The Catcher in the Rye");
    Book book2(201, "Harper Lee", "To Kill a Mockingbird");
    Book book3(301, "George Orwell", "1984");
    Book book4(401,"Harper Lee","To Kill a Mockingbird");
    Book book5(501,"The Great Gatsby","F. Scott Fitzgerald");
    Book book6(601,"Pride and Prejudice","Jane Austen");
    Book book7(701,"The Lord of the Rings" ,"J.R.R. Tolkien");
    Book book8(801,"The Da Vinci Code"," Dan Brown");
    Book book9(901,"The Chronicles of Narnia","C.S. Lewis");
    Book book10(1001,"The C++ Programming Language","Bjarne Stroustrup");



//adding book to the library management system
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    library.addBook(book6);
    library.addBook(book7);
    library.addBook(book8);
    library.addBook(book9);
    library.addBook(book10);


//enter choice
    int choice;
    do {
        cout << "\nWelcome to the Library Management System\n";
        cout << "1. Display Catalog\n";
        cout << "2. Check Book Availability\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                library.displayCatalog();
                break;
            case 2:
                int bookId;
                cout << "Enter book ID: ";
                cin >> bookId;
                if (library.checkAvailability(bookId)) {
                                    cout << "Book is available.\n";
                } else {
                    cout << "Book is not available.\n";
                }
                break;
            case 3:
                cout << "Enter book ID to checkout: ";
                cin >> bookId;
                library.checkoutBook(bookId);
                break;
            case 4:
                cout << "Enter book ID to return: ";
                cin >> bookId;
                library.returnBook(bookId);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}