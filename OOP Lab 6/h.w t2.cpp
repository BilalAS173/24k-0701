#include <iostream>
using namespace std;
class Vehicle {
protected:
    double price;

public:
    Vehicle(double p) : price(p) {}

    void showPrice() {
        cout << "Price: $" << price << endl;
    }
};

class Car : public Vehicle {
protected:
    int seatingCapacity;
    int numDoors;
    string fuelType;

public:
    Car(double p, int seats, int doors, string fuel) 
        : Vehicle(p), seatingCapacity(seats), numDoors(doors), fuelType(fuel) {}

    void showCarDetails() {
        showPrice();
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicle {
protected:
    int numCylinders;
    int numGears;
    int numWheels;

public:
    Motorcycle(double p, int cylinders, int gears, int wheels) 
        : Vehicle(p), numCylinders(cylinders), numGears(gears), numWheels(wheels) {}

    void showMotorcycleDetails() {
        showPrice();
        cout << "Number of Cylinders: " << numCylinders << endl;
        cout << "Number of Gears: " << numGears << endl;
        cout << "Number of Wheels: " << numWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType;

public:
    Audi(double p, int seats, int doors, string fuel, string model) 
        : Car(p, seats, doors, fuel), modelType(model) {}

    void showAudiDetails() {
        showCarDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double p, int cylinders, int gears, int wheels, string make) 
        : Motorcycle(p, cylinders, gears, wheels), makeType(make) {}

    void showYamahaDetails() {
        showMotorcycleDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi myAudi(5000, 5, 4, "Petrol", "B3");
    cout << "Audi Car Details:\n";
    myAudi.showAudiDetails();
    Yamaha myYamaha(15000, 2, 6, 2, "YZF-R3");
    cout << "Yamaha Motorcycle Details:\n";
    myYamaha.showYamahaDetails();

    return 0;
}
