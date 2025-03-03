#include <iostream>
#include <vector>
using namespace std;
class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};
class Catalog {
public:
    void listBooks(const vector<Book*>& books) const {
        if (books.empty()) {
            cout << "No books in the catalog.\n";
            return;
        }
        cout << "Books in catalog:\n";
        for (const auto& book : books) {
            book->display();
        }
    }

    Book* findBookByISBN(const vector<Book*>& books, const string& isbn) const {
        for (const auto& book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library {
private:
    Catalog catalog;  
    vector<Book*> books;  

public:
    string name;
    string address;

    Library(string n, string addr) : name(n), address(addr) {}

    void addBook(Book* book) {
        books.push_back(book);
        cout << "Book added: " << book->title << endl;
    }

    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i]->isbn == isbn) {
                cout << "Removing book: " << books[i]->title << endl;
                books.erase(books.begin() + i);
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void showCatalog() const {
        catalog.listBooks(books);
    }

    void searchBookByISBN(const string& isbn) const {
        Book* book = catalog.findBookByISBN(books, isbn);
        if (book) {
            cout << "Book found:\n";
            book->display();
        } else {
            cout << "Book not found in catalog.\n";
        }
    }
};

int main() {
    Library lib("City Library", "123 Library St");
    Book book1("C++ Basics", "John Doe", "1111");
    Book book2("Data Structures", "Jane Smith", "2222");
    Book book3("Algorithms", "Robert Brown", "3333");

    lib.addBook(&book1);
    lib.addBook(&book2);
    lib.addBook(&book3);
    cout << "\n--- Catalog ---\n";
    lib.showCatalog();

    cout << "\n--- Searching for a Book ---\n";
    lib.searchBookByISBN("3333");
    cout << "\n--- Removing a Book ---\n";
    lib.removeBook("2222");

    cout << "\n--- Catalog After Removal ---\n";
    lib.showCatalog();

    return 0;
}
