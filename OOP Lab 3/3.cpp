#include<iostream>
using namespace std;
class glass {
    public:
    int liquidlevel;

    void drink (int milliletres) {
    if ((liquidlevel-milliletres)<100) {
        refill();
    }
    }
   void refill () {
        liquidlevel=200;
    }
};
int main () {
    glass g1;
    int milliletres;
    g1.liquidlevel=200;
    do {
cout<<"Enter the amount of litres to drink (Enter 0 to stop): "<<endl;
cin>>milliletres;
g1.drink(milliletres);
    }while(milliletres!=0);
    
}