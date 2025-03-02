#include <iostream>
using namespace std;
class Car {
public:
    mutable int horsepower; 
    mutable int seating_capacity;
    mutable int no_of_speakers;
    Car(int hp, int sc, int ns) : horsepower(hp), seating_capacity(sc), no_of_speakers(ns) {}
    void display() const {
        cout << "Horsepower: " << horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
    void modifyattributes(int hp, int sc, int ns) const {
        horsepower = hp;
        seating_capacity = sc;
        no_of_speakers = ns;
    }
};
int main() {
    Car myCar(100, 5, 6);
    cout << "Original values:" << endl;
    myCar.display();
    myCar.modifyattributes(150, 3, 7);
    cout << "Updated values:" << endl;
    myCar.display();
    return 0;
}
