#include <iostream>
#include <cstdio>
using namespace std;
int main () {
string moviename;
float adulttktp, childtktp, grossamount, netsale, amountdonated, perdonation;
int noofadulttkt, noofchildtkt, nooftickets;
cout<<"Enter the movie name: "<<endl;
cin>>moviename;
cout<<"Enter the adult ticket price: "<<endl;
cin>>adulttktp;
cout<<"Enter the child ticket price: "<<endl;
cin>>childtktp;
cout<<"Enter the number of adult tickets sold: "<<endl;
cin>>noofadulttkt;
cout<<"Enter the number of child tickets sold: "<<endl;
cin>>noofchildtkt;
cout<<"Enter the percentage of gross amount to be donated to charity: "<<endl;
cin>>perdonation;
nooftickets=noofadulttkt+noofchildtkt;
grossamount=noofadulttkt*adulttktp + noofchildtkt*childtktp;
amountdonated=(perdonation/100)*grossamount;
netsale=grossamount-amountdonated;
cout<<"Movie Name: "<<moviename<<endl;
cout<<"Number of tickets sold: "<<nooftickets<<endl;
printf("Gross Amount: %.2f \n",grossamount);
cout<<"Percentage of gross amount donated: "<<perdonation<<endl;
printf("Amount donated: %.2f \n",amountdonated);
printf("Net Sale: %.2f",netsale);
}