#include<iostream>
using namespace std;
class wallet {
private:
float balance;
float ddepositlimit=500000;
float dwithdrawlimit=300000;
public:
wallet (float b) : balance (b) {}
wallet () {
    //default constructor
}

void deposit (float a) {
    if (a>0 && a<=ddepositlimit) {
        balance+=a;
        cout<<"You have successfully deposited PKR "<<a<< "."<<endl;
    }
    else {
        cout<<"Deposit unsuccesful as you are exceeding your daily deposit limit."<<endl;
    }

}
void withdraw (float a) {
    if (a>0 && a<=dwithdrawlimit) {
        balance-=a;
        cout<<"You have successfully withdrawn PKR "<<a<< "."<<endl;
    }
    else {
        cout<<"Withdrawl unsuccesful as you are exceeding your daily withdrawl limit."<<endl;
    }

}

};
class user : public wallet {
string name;
string id;

public:
user (float b, string n, string i): wallet (b), name(n), id (i) {}

};
int main () {
    user w (100000, "David", "PK123");
    w.deposit(400000);
    w.withdraw(350000);
    user h (700000, "Harry", "PK124");
    h.deposit(600000);
    h.withdraw (300000);
    return 0;
    

}
