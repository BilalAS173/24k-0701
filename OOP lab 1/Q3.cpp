#include<iostream>
using namespace std;
int main (int argc, char* argv[]) {
    string customername;
    int unitsconsumed, customerid;
    float total, surchargeamount=0.0, amountcharges;
    cout<<"Enter your name: "<<endl;
    cin>>customername;
    cout<<"Enter your customer ID: "<<endl;
    cin>>customerid;
    cout<<"Enter your number of units consumed: "<<endl;
    cin>>unitsconsumed;

    if(unitsconsumed<=199) {
    amountcharges=unitsconsumed*16.20;
    total=amountcharges;
    }
    else if (unitsconsumed>199 && unitsconsumed<300) {
     amountcharges=unitsconsumed*20.10;
     total=amountcharges;
    }
    else if (unitsconsumed>=300 && unitsconsumed<500) {
  amountcharges=unitsconsumed*27.10;
     total=amountcharges;
    }
    else if (unitsconsumed>=500) {
  amountcharges=unitsconsumed*35.90;
     surchargeamount=0.15*amountcharges;
     total=amountcharges+surchargeamount;
    }
    cout<<"Name: "<<customername<<endl;
    cout<<"ID: "<<customerid<<endl;
    cout<<"Units consumed: "<<unitsconsumed<<endl;
    cout<<"Amount charges: "<<amountcharges<<endl;
    cout<<"Surcharge amount: "<<surchargeamount<<endl;
    cout<<"Total amount to be paid is: "<<total<<endl;
}