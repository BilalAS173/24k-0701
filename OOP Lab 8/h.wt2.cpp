#include <iostream>
using namespace std;
class shape {
protected:
float length;
float width;
public:
shape(float x, float y): length(x), width(y) {}
shape () : length(0), width(0) {}
float area () const {
   return length*width;
   }
float operator+(const shape& other) const {
    return this->area() + other.area();  
}
};
int main () {
    shape shape1(10,5);
    cout<<"Shape 1 area: "<<shape1.area()<<endl;
    shape shape2(2,3);
    cout<<"Shape 2 area: "<<shape2.area()<<endl;
    float totalArea = shape1 + shape2;
    cout << "Total area: " << totalArea;  
}