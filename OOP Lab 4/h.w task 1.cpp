#include<iostream>
using namespace std;
class circle {
    private:
float radius;
float pie=3.142;
float area;
float perimeter;
public:
circle (float radius): radius(radius) {}
void setarea () {
area=pie*radius*radius;
}
float getarea () {
    return area;
    }
void setperimeter () {
        perimeter=2*pie*radius;
        }
float getperimeter () {
    return perimeter;
            }

};
int main () {
    float r;
    cout<<"Enter the radius of the circle: "<<endl;
    cin>>r;
    circle obj(r);
    obj.setarea();
    obj.setperimeter();
    cout<<"Area is: "<<obj.getarea()<<endl;
    cout<<"Perimeter is: "<<obj.getperimeter()<<endl;
    
}
