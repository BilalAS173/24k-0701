#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
 
    Book(string authorName, string bookTitle, double bookPrice, string bookPublisher, int bookStock) {
        author = authorName;
        title = bookTitle;
        price = bookPrice;
        publisher = bookPublisher;
        stock = bookStock;
    }

    string getAuthor() const { 
        return author; 
    }
    string getTitle() const { 
        return title;
     }
    double getPrice() const { 
        return price; 
    }
    string getPublisher() const {
        return publisher; 
    }
    int getStock() const { 
        return stock;
    }
    bool isAvailable(int requestedCopies) const {
        return stock >= requestedCopies;
    }
    void sellBooks(int soldCopies) {
        stock -= soldCopies;
    }

    void displayDetails() const {
        cout << "Author: " << author << "\nTitle: " << title << "\nPrice: $" << price
             << "\nPublisher: " << publisher << "\nStock: " << stock << endl;
    }
};

class BookShop {
private:
    Book* inventory[100]; 
    int totalBooks; 

public:
    // Constructor
    BookShop() {
        totalBooks = 0;
    }

    void addBook(string author, string title, double price, string publisher, int stock) {
        inventory[totalBooks] = new Book(author, title, price, publisher, stock);
        totalBooks++;
    }

    void searchBook(string title, string author) {
        bool found = false;
        for (int i = 0; i < totalBooks; i++) {
            if (inventory[i]->getTitle() == title && inventory[i]->getAuthor() == author) {
                found = true;
                inventory[i]->displayDetails();
                cout << "Enter the number of copies you want to buy: ";
                int copies;
                cin >> copies;
                if (inventory[i]->isAvailable(copies)) {
                    inventory[i]->sellBooks(copies);
                    cout << "Total cost for " << copies << " copies: $" << inventory[i]->getPrice() * copies << endl;
                } else {
                    cout << "Required copies not in stock" << endl;
                }
            }
        }

        if (!found) {
            cout << "The book is not available in the inventory." << endl;
        }
    }
};

int main() {
    
    BookShop shop;

    shop.addBook("J.K. Rowling", "Harry Potter", 49.99, "Bloomsbury", 50);
    shop.addBook("George Orwell", "1984", 15.79, "The Silent Patient", 60);

    string title, author;
    cout << "Enter book title: ";
    cin.ignore(); 
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    shop.searchBook(title, author);

    return 0;
}
