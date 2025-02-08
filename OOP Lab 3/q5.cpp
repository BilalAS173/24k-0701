#include <iostream>
#include <string>
#include <cstdlib>  
using namespace std;

class Book {
private:
    string bookName;   
    int isbnNumber;   
    string authorName; 
    string publisher; 

public:

    Book() {
        this->bookName = "";
        this->isbnNumber = 0;
        this->authorName = "";
        this->publisher = "";
    }

  
    Book(string bookName, int isbnNumber, string authorName, string publisher) {
        this->bookName = bookName;
        this->isbnNumber = isbnNumber;
        this->authorName = authorName;
        this->publisher = publisher;
    }

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


    if (argc < REQUIRED_ARGS) {
        cout << "Usage: " << argv[0] 
             << " <Book1Name> <Book1ISBN> <Book1Author> <Book1Publisher> "
             << "<Book2Name> <Book2ISBN> <Book2Author> <Book2Publisher> "
             << "...\n";
        return 1;
    }

    Book books[NUM_BOOKS];

    int index = 1;  
    for (int i = 0; i < NUM_BOOKS; i++) {
        string name = argv[index++];
   
        int isbn = stoi(argv[index++]);
        string author = argv[index++];
        string publisher = argv[index++];
        
        books[i] = Book(name, isbn, author, publisher);
    }

    cout << "Book Details:\n";
    for (int i = 0; i < NUM_BOOKS; i++) {
        cout << "\nBook " << i + 1 << " Info:\n";
        cout << books[i].getBookInfo() << "\n";
    }

    return 0;
}
