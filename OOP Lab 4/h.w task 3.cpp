#include <iostream>
#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;

public:
    // Constructor
    Invoice(std::string partNum, std::string partDesc, int qty, double price) 
        : partNumber(partNum), partDescription(partDesc) {
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0.0) ? price : 0.0;
    }

    // Function to calculate invoice amount
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};
