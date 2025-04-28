#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

// UUID generator
string generateUUID() {
    const string chars = "0123456789abcdef";
    string uuid;
    for (int i = 0; i < 32; i++) {
        uuid += chars[rand() % 16];
        if (i == 7 || i == 11 || i == 15 || i == 19) {
            uuid += '-';
        }
    }
    return uuid;
}

class Entity {
protected:
    string id;
public:
    Entity() : id(generateUUID()) {}
    string getId() const { return id; }
    virtual void saveToFile(ofstream& file) const = 0;  // Made const
};

class User : public Entity {
    string firstName, lastName, address, email;
public:
    User(string fn, string ln, string addr, string em)
        : firstName(fn), lastName(ln), address(addr), email(em) {}
    
    void saveToFile(ofstream& file) const override {  // Made const
        file << "user," << id << "," << firstName << "," 
             << lastName << "," << address << "," << email << "\n";
    }
    string getFirstName() const { return firstName; }
};

class Product : public Entity {
    string name, description;
    int price;
public:
    Product(string n, string desc, int p) 
        : name(n), description(desc), price(p) {}
    
    void saveToFile(ofstream& file) const override {  // Made const
        file << "product," << id << "," << name << "," 
             << description << "," << price << "\n";
    }
    string getName() const { return name; }
};

class Order : public Entity {
    string userId, productId;
    int total;
public:
    Order(string uid, string pid, int t) 
        : userId(uid), productId(pid), total(t) {}
    
    void saveToFile(ofstream& file) const override {  // Made const
        file << "order," << id << "," << userId << "," 
             << productId << "," << total << "\n";
    }
    string getUserId() const { return userId; }
    string getProductId() const { return productId; }
};

class Database {
    vector<User> users;
    vector<Product> products;
    vector<Order> orders;
    string filename = "database.txt";
    
    void loadData() {
        ifstream file(filename);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string type;
            getline(ss, type, ',');
            
            if (type == "user") {
                string id, fn, ln, addr, em;
                getline(ss, id, ',');
                getline(ss, fn, ',');
                getline(ss, ln, ',');
                getline(ss, addr, ',');
                getline(ss, em, ',');
                users.push_back(User(fn, ln, addr, em));
                users.back().getId() = id;
            }
            else if (type == "product") {
                string id, name, desc, priceStr;
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, desc, ',');
                getline(ss, priceStr, ',');
                products.push_back(Product(name, desc, stoi(priceStr)));
                products.back().getId() = id;
            }
            else if (type == "order") {
                string id, uid, pid, totalStr;
                getline(ss, id, ',');
                getline(ss, uid, ',');
                getline(ss, pid, ',');
                getline(ss, totalStr, ',');
                orders.push_back(Order(uid, pid, stoi(totalStr)));
                orders.back().getId() = id;
            }
        }
        file.close();
    }

public:
    Database() {
        srand(123);
        loadData();
    }
    
    void addUser(const User& u) { users.push_back(u); }
    void addProduct(const Product& p) { products.push_back(p); }
    void addOrder(const Order& o) { orders.push_back(o); }
    
    vector<string> getProductsForUser(const string& firstName) const {
        vector<string> result;
        
        // Find matching users
        vector<string> userIds;
        for (const User& u : users) {
            if (u.getFirstName() == firstName) {
                userIds.push_back(u.getId());
            }
        }
        
        // Find their orders
        for (const Order& o : orders) {
            for (const string& uid : userIds) {
                if (o.getUserId() == uid) {
                    for (const Product& p : products) {
                        if (p.getId() == o.getProductId()) {
                            result.push_back(p.getName());
                        }
                    }
                }
            }
        }
        return result;
    }
    
    void saveAll() const {  // Made const
        ofstream file(filename);
        for (const User& u : users) u.saveToFile(file);
        for (const Product& p : products) p.saveToFile(file);
        for (const Order& o : orders) o.saveToFile(file);
        file.close();
    }
};

int main() {
    Database db;
    
    // Create all objects first
    User u1("Linus", "Torvalds", "123 Linux Way", "linus@linux.com");
    User u2("John", "Doe", "456 Main St", "john@example.com");
    
    Product p1("Linux OS", "Open-source OS", 0);
    Product p2("Git", "Version control", 0);
    Product p3("Text Editor", "Code editor", 20);
    
    // Add to database
    db.addUser(u1);
    db.addUser(u2);
    db.addProduct(p1);
    db.addProduct(p2);
    db.addProduct(p3);
    
    // Create orders after products exist
    db.addOrder(Order(u1.getId(), p1.getId(), 0));
    db.addOrder(Order(u1.getId(), p2.getId(), 0));
    db.addOrder(Order(u2.getId(), p3.getId(), 20));
    
    // Perform query
    vector<string> products = db.getProductsForUser("Linus");
    cout << "Products ordered by Linus:\n";
    for (const string& name : products) {
        cout << "- " << name << "\n";
    }
    
    db.saveAll();
    return 0;
}