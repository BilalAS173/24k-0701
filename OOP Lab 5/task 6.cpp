#include <iostream>
#include <vector>
using namespace std;
struct MenuItem {
    string name;
    string type;  
    double price;
};
class CoffeeShop {
public:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders; 

    CoffeeShop(string shopName, vector<MenuItem> menuItems)
        : name(shopName), menu(menuItems) {}

    string addOrder(string itemName) {
        for (auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;  // Returns list of pending orders
    }

    double dueAmount() {
        double total = 0;
        for (auto& order : orders) {
            for (auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in menu!";
        MenuItem cheapest = menu[0];
        for (auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Coffee", "drink", 3.5},
        {"Tea", "drink", 2.5},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 4.5}
    };
    CoffeeShop shop("Cafe Java", menu);
    cout << shop.addOrder("Coffee") << endl;  
    cout << shop.addOrder("Burger") << endl;  
    cout << shop.fulfillOrder() << endl;      
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (auto& d : drinks) cout << d << " ";
    cout << endl;

    return 0;
}
