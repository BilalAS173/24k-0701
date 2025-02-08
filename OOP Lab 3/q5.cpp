#include <iostream>
#include <string>
#include <cstdlib>  // For stoi
using namespace std;

class Book {
private:
    string bookName;   // Book name
    int isbnNumber;    // ISBN number
    string authorName; // Author name
    string publisher;  // Publisher

public:
    // Default constructor
    Book() {
        this->bookName = "";
        this->isbnNumber = 0;
        this->authorName = "";
        this->publisher = "";
    }

    // Parameterized constructor
    Book(string bookName, int isbnNumber, string authorName, string publisher) {
        this->bookName = bookName;
        this->isbnNumber = isbnNumber;
        this->authorName = authorName;
        this->publisher = publisher;
    }

    // Query methods for each instance variable
    string getBookName() const {
        return this->bookName;
    }

    int getIsbnNumber() const {
        return this->isbnNumber;
    }

    string getAuthorName() const {
        return this->authorName;
    }

    string getPublisher() const {
        return this->publisher;
    }

    // Method that returns a string containing all the book's details
    string getBookInfo() const {
        return "Book Name: " + this->bookName + "\n" +
               "ISBN Number: " + to_string(this->isbnNumber) + "\n" +
               "Author: " + this->authorName + "\n" +
               "Publisher: " + this->publisher;
    }
};

int main(int argc, char* argv[]) {
    const int NUM_BOOKS = 5;
    const int ARGS_PER_BOOK = 4; // Each book requires 4 parameters
    const int REQUIRED_ARGS = 1 + NUM_BOOKS * ARGS_PER_BOOK;

    // Check if enough command-line arguments are provided.
    if (argc < REQUIRED_ARGS) {
        cout << "Usage: " << argv[0] 
             << " <Book1Name> <Book1ISBN> <Book1Author> <Book1Publisher> "
             << "<Book2Name> <Book2ISBN> <Book2Author> <Book2Publisher> "
             << "...\n";
        return 1;
    }

    // Create an array of 5 Book objects.
    Book books[NUM_BOOKS];

    // Parse command-line arguments. argv[0] is the program name.
    int index = 1;  // Start at argv[1]
    for (int i = 0; i < NUM_BOOKS; i++) {
        string name = argv[index++];
        // Convert the ISBN argument (a C-string) to an integer using stoi.
        int isbn = stoi(argv[index++]);
        string author = argv[index++];
        string publisher = argv[index++];
        
        books[i] = Book(name, isbn, author, publisher);
    }

    // Output the information for each book.
    cout << "Book Details:\n";
    for (int i = 0; i < NUM_BOOKS; i++) {
        cout << "\nBook " << i + 1 << " Info:\n";
        cout << books[i].getBookInfo() << "\n";
    }

    return 0;
}
