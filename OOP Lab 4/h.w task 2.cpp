#include<iostream>
using namespace std;
class bank{
    private:
    float balance;
    public:
    void setbalance (float number) {
        balance=number;
    }
    float getbalance () {
        return balance;
    }
    float credit (float amount) {
        balance+=amount;
        return balance;
    }
    float debit (float amount) {
        if (balance>0 || amount>balance) {
            balance-=amount;
            return balance;
        }
        else {
            cout<<"Insufficient balance for the transaction. "<<endl;
        }
    }


};
int main () {
    float amount;
bank obj;
cout<<"Enter your balance: "<<endl;
cin>>amount;
obj.setbalance(amount);
cout<<"Enter the amount to credit: "<<endl;
cin>>amount;
float b=obj.credit(amount);
cout<<"Your updated balance is: "<<b<<endl;
cout<<"Enter the amount to debit: "<<endl;
cin>>amount;
float a=obj.debit(amount);
cout<<"Your updated balance is: "<<a<<endl;
}
