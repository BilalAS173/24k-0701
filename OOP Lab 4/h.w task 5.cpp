#include <iostream>
#include <string>
#include <vector>
using namespace std;
class menuitem {
public:
    string name;
    string type;
    double price;

    menuitem(string itemName, string itemType, double itemPrice) {
        name = itemName;
        type = itemType;
        price = itemPrice;
    }
};
class coffeeshop {
private:
    string name;
    vector<menuitem*> menu;
    vector<string> orders;

public:
    coffeeshop(string shopName) {
        name = shopName;
    }

    void addOrder(string itemName) {
        bool itemFound = false;
        for (auto& item : menu) {
            if (item->name == itemName) {
                orders.push_back(itemName);
                itemFound = true;
                cout << "Order for " << itemName << " added successfully." << endl;
                break;
            }
        }
        if (!itemFound) {
            cout << "This item is currently unavailable." << endl;
        }
    }
    void fulfillOrder() {
        if (!orders.empty()) {
            cout << "The " << orders[0] << " is ready." << endl;
            orders.erase(orders.begin());
        } else {
            cout << "All orders have been fulfilled." << endl;
        }
    }
    void listOrders() {
        if (orders.empty()) {
            cout << "No orders yet." << endl;
        } else {
            cout << "Orders list: ";
            for (const auto& order : orders) {
                cout << order << " ";
            }
            cout << endl;
        }
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item->name == order) {
                    total += item->price;
                    break;
                }
            }
        }
        return total;
    }

    void addMenuItem(string itemName, string itemType, double itemPrice) {
        menu.push_back(new menuitem(itemName, itemType, itemPrice));
    }
    string cheapestItem() {
        double minPrice = 99999;
        string cheapest;
        for (const auto& item : menu) {
            if (item->price < minPrice) {
                minPrice = item->price;
                cheapest = item->name;
            }
        }
        return cheapest;
    }

    void drinksOnly() {
        cout << "Drinks on the menu: ";
        for (const auto& item : menu) {
            if (item->type == "drink") {
                cout << item->name << " ";
            }
        }
        cout << endl;
    }
    void foodOnly() {
        cout << "Food available: ";
        for (const auto& item : menu) {
            if (item->type == "food") {
                cout << item->name << " ";
            }
        }
        cout << endl;
    }
    ~coffeeshop() {
        for (auto& item : menu) {
            delete item;
        }
    }
};
int main() {
    coffeeshop shop("Coffee Time");
    shop.addMenuItem("Latte", "drink", 3.50);
    shop.addMenuItem("Cappuccino", "drink", 4.00);
    shop.addMenuItem("Biscuit", "food", 2.50);
    shop.addMenuItem("Sandwich", "food", 5.00);
    shop.addOrder("Latte");
    shop.addOrder("Biscuit");
    shop.listOrders();
    shop.fulfillOrder();
    cout << "Total due amount: $" << shop.dueAmount() << endl;
    shop.drinksOnly();
    shop.foodOnly();
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    return 0;
}
