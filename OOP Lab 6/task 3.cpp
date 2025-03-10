#include <iostream>
using namespace std;

// Base Employee Class
class Employee {
protected:
    string name;
    string id;
public:
    Employee(string n, string i) : name(n), id(i) {}
    string getName() { return name; } // Getter function (optional)
};

// Abstract Interfaces
class IOrderTaker {
public:
    virtual void takeOrder() = 0; // Pure virtual function
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual float calculateBill(float cost1, float cost2) = 0;
    virtual ~IBiller() {}
};

// Concrete Employee Roles
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(string n, string i) : Employee(n, i) {}

    void takeOrder() override {
        cout << name << " (Waiter) has taken the order.\n";
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(string n, string i) : Employee(n, i) {}

    void prepareOrder() override {
        cout << name << " (Chef) is preparing the order.\n";
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(string n, string i) : Employee(n, i) {}

    float calculateBill(float cost1, float cost2) override {
        return cost1 + cost2; // Simple bill calculation
    }
};

// Multiple Role Employee (Manager)
class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(string n, string i) : Employee(n, i) {}

    void takeOrder() override {
        cout << name << " (Manager) is taking the order.\n";
    }

    float calculateBill(float cost1, float cost2) override {
        return (cost1 + cost2) * 0.9; // 10% discount for manager billing
    }
};

// Menu System
class Menu {
protected:
    float item1Price, item2Price;
public:
    Menu(float p1, float p2) : item1Price(p1), item2Price(p2) {}

    virtual float totalCost() {
        return item1Price + item2Price;
    }
};

class FoodMenu : public Menu {
public:
    FoodMenu(float p1, float p2) : Menu(p1, p2) {}

    float totalCost() override {
        return Menu::totalCost() * 0.9; // 10% discount for food combos
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(float p1, float p2) : Menu(p1, p2) {}

    float totalCost() override {
        return Menu::totalCost() * 1.05; // 5% tax on beverages
    }
};

// Main Function to Test
int main() {
    // Creating Employee Objects
    Waiter waiter("John", "W001");
    Chef chef("Alice", "C002");
    Cashier cashier("Bob", "CA003");
    Manager manager("Sarah", "M004");

    // Taking an order
    waiter.takeOrder();

    // Preparing the order
    chef.prepareOrder();

    // Selecting menu and calculating cost
    FoodMenu food(500, 200);
    BeverageMenu beverage(150, 100);

    cout << "Food total cost (with discount): " << food.totalCost() << endl;
    cout << "Beverage total cost (with tax): " << beverage.totalCost() << endl;

    // Billing
    cout << "Total Bill (Cashier): " << cashier.calculateBill(food.totalCost(), beverage.totalCost()) << endl;
    cout << "Total Bill (Manager - with discount): " << manager.calculateBill(food.totalCost(), beverage.totalCost()) << endl;

    return 0;
}
