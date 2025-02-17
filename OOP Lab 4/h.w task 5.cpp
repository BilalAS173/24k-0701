#include <iostream>
#include <vector>
#include <string>

struct MenuItem {
    std::string name;
    std::string type;
    double price;
};

class CoffeeShop {
private:
    std::string name;
    std::vector<MenuItem> menu;
    std::vector<std::string> orders;

public:
    CoffeeShop(std::string shopName, std::vector<MenuItem> menuItems) 
        : name(shopName), menu(menuItems) {}

    std::string addOrder(std::string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added.";
            }
        }
        return "This item is currently unavailable.";
    }

    std::string fulfillOrder() {
        if (!orders.empty()) {
            std::string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready.";
        }
        return "All orders have been fulfilled.";
    }

    std::vector<std::string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }
};
