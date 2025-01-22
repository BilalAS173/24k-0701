#include <iostream>
#include <cstdio>
using namespace std;
int main () {
float weightinkgs, weightinpounds;
cout<<"Enter the weight in kilograms: "<<endl;
cin>>weightinkgs;
weightinpounds=weightinkgs*2.2;
printf("Weight in Pounds is: %.2f",weightinpounds);
}