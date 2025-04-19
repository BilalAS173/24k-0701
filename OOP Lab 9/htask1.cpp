#include <iostream>
using namespace std;
class Shape {
public:
    virtual double getArea() = 0;
 
    virtual ~Shape() {

    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() override {
        return length * width;
    }
};
class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* rectangle = new Rectangle(12.0, 4.0);
    Shape* triangle = new Triangle(8.0, 6.0);
    cout << "Area of Rectangle: " << rectangle->getArea() << endl;
    cout << "Area of Triangle: " << triangle->getArea() << endl;
    delete rectangle;
    delete triangle;
    
    return 0;
}