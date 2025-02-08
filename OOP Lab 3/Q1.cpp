#include<iostream>
using namespace std;

class User {
    public:
    int age;
    string name;
};
int main () {
    User u1;
    u1.name="Teo";
    u1.age=24;
    cout<<"My name is "<<u1.name<<" and my age is "<<u1.age<<endl;
}
