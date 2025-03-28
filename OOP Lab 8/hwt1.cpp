#include <iostream>
#include <vector>

using namespace std;

class A {
protected:
int x;
public:
A(int y): x(y) {}
A() {
    //default constructor
}
A& operator-- () {
x*=4;
return *this;
}
A operator-- (int ) {
    A temp=*this;
    x/=4;
    return temp;
}
void display () {
    cout<<"X: "<<x<<endl;
}
};
int main () {
    A obj(20);
    cout<<"Original object: "<<endl;
    obj.display(); 
    cout<<"Pre fix (obj++): "<<endl;
    A& obj2=--obj;
    obj2.display();
    cout<<"Post fix (obj--): "<<endl;
    A obj1=obj--;
    obj.display();
   
}