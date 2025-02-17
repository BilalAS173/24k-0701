#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partnumber;
    string partdescription;
    int quantity;
    double priceperitem;
public:
    Invoice(string partNum, string partDesc, int qty, double price) 
        : partnumber(partNum), partdescription(partDesc) {
        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }
        if (price > 0.0) {
            priceperitem = price;
        } else {
            priceperitem = 0.0;
        }
    }

    double getInvoiceAmount() const {
        return quantity * priceperitem;
    }

    string getPartNumber() const { 
        return partnumber; 
    }
    string getPartDescription() const { 
        return partdescription;
     }
    int getQuantity() const {
         return quantity; 
        }
    double getPricePerItem() const { 
        return priceperitem;
     }

    void setQuantity(int qty) {
        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }
    }

    void setPricePerItem(double price) {
        if (price > 0.0) {
            priceperitem = price;
        } else {
            priceperitem = 0.0;
        }
    }
};

int main() {
    Invoice invoice1("B456", "Hammer", 20, 16.80);

    cout << "Invoice Details:" << endl;
    cout << "Part Number: " << invoice1.getPartNumber() << endl;
    cout << "Part Description: " << invoice1.getPartDescription() << endl;
    cout << "Quantity: " << invoice1.getQuantity() << endl;
    cout << "Price per Item: " << invoice1.getPricePerItem() << endl;

    cout << "Total Invoice Amount is: " << invoice1.getInvoiceAmount() << endl;
    invoice1.setQuantity(15);
    invoice1.setPricePerItem(20.00);
    cout << "Updated Invoice Details:" << endl;
    cout << "Quantity: " << invoice1.getQuantity() << endl;
    cout << "Price per Item: " << invoice1.getPricePerItem() << endl;
    cout << "Total Invoice Amount: " << invoice1.getInvoiceAmount() << endl;

}
