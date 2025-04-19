#include <iostream>
#include <string>
using namespace std;
class Car {
protected:
    string model;
    double price;
public:
    Car(const string& m, double p) : model(m), price(p) {}
   string getModel() const {
     return model;
     }
    double getPrice() const { 
        return price; 
    }
    void setModel(const string& m) { 
        model = m; 
    }
    virtual void setPrice(double p) = 0;
    virtual ~Car() {}
};

class Color : public Car {
private:
    string color;
public:
    Color(const string& m, double p, const string& c) 
        : Car(m, p), color(c) {}
    
    void setPrice(double p) override {
        if (color == "Red") {
            price = p * 1.3; 
        } else {
            price = p;
        }
    }
    
    string getColor() const { return color; }
};

class Company : public Car {
private:
    string company;
public:
    Company(const string& m, double p, const string& comp) 
        : Car(m, p), company(comp) {}
    void setPrice(double p) override {
        if (company == "BMW") {
            price = p * 1.3; 
        } else {
            price = p;
        }
    }
    
    string getCompany() const { return company; }
};

int main() {
    Color redCar("Sedan", 30000.0, "Red");
    Company bmwCar("X5", 40000.0, "BMW");
    
    redCar.setPrice(30000.0);
    bmwCar.setPrice(40000.0);
 
    cout << "Color Car - Model: " << redCar.getModel() 
         << ", Price: $" << redCar.getPrice()
         << ", Color: " << redCar.getColor() << endl;
    
    cout << "Company Car - Model: " << bmwCar.getModel() << ", Price: $" << bmwCar.getPrice() << ", Company: " << bmwCar.getCompany() << endl;
    
    return 0;
}