#include <iostream>
#include <vector>
using namespace std;
class Car {
public:
    string name;
    int id;

    Car(string n, int id) : name(n), id(id) {}

    void display() const {
        cout << "Car details: " <<endl<<"ID: "<< id << ", Name: " << name << endl;
    }
};

class Garage {
private:
    vector<Car*> cars; 
public:
    void parkCar(Car* car) {
        if (car) {
            cars.push_back(car);
            cout << "Car " << car->name << " parked in the garage successfully." << endl;
        }
    }
    void listCars() const {
        cout << "Cars in the garage are the following: "<<endl;
        for (const auto& car : cars) {
            if (car)
                car->display();
        }
    }
};

int main() {
    Car car1("Toyota", 100);
    Car car2("Honda", 101);
    Car car3("BMW", 102);
    Car car4("Ferrari",103);
    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    myGarage.parkCar(&car3);
    myGarage.listCars();

    // Cars will be destroyed when main function ends

    return 0;
}
