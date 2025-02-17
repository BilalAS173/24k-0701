#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;
    std::string publisher;
    int stock;

public:
    // Constructor
    Book(std::string t, std::string a, double p, std::string pub, int s)
        : title(t), author(a), price(p), publisher(pub), stock(s) {}

    // Function to check availability and process order
    void processOrder(int copies) {
        if (copies <= stock) {
            std::cout << "Total Cost: " << (copies * price) << std::endl;
            stock -= copies;
        } else {
            std::cout << "Required copies not in stock.\n";
        }
    }

    // Function to check availability
    bool isAvailable(std::string searchTitle, std::string searchAuthor) const {
        return (title == searchTitle && author == searchAuthor);
    }

    // Function to display book details
    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nPrice: " << price << "\nPublisher: " << publisher
                  << "\nStock: " << stock << std::endl;
    }
};
