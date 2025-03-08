#include<iostream>
using namespace std;
class bankaccount {
    protected:
    string accno;
    float balance;
    bool isfreeze;
  private:
  float acclimit=50000;
    public:
    bankaccount (string a, float b) : accno(a), balance(b) {}
    float getbalance () {
        return balance;
    }
    void withdraw (float amount) {
        balance-=amount;
        cout<<"Amount deducted successfully."<<endl;
    }
    void deposit (float amount) {
        balance+=amount;
        cout<<"Amount deposited successfully."<<endl;
    }
    void setFreeze(bool status) {
        isfreeze = status;
    }
    bool getissfreeze () {
        return isfreeze;
    }
    
    void setacclimit (float a) {
        acclimit=a;
        cout<<"Account limit successfully updated to:"<<a<<endl;
    }
    float getacclimit () {
        return acclimit;
    }
};
class savingsaccount: public bankaccount {
public:
savingsaccount(string a, float b) : bankaccount(a, b) {}
void interest () {
    balance+=0.1*balance;
    cout<<"Monthly 10% interest applied. Your updated balance is: "<<balance<<endl;
}
};
class buisnessaccount : public bankaccount {
public:
buisnessaccount(string a, float b) : bankaccount(a, b) {}
    void taxdeduction () {
    balance-=0.05*balance;
    cout<<"Monthly 5% tax deducted. Your updated balance is: "<<balance<<endl;
    }

};
class checkingaccount : public bankaccount {
    public:
    checkingaccount(string a, float b) : bankaccount(a, b) {}
    float overdraftlimit=-1000;
    bool checkforoverdraft (float a) {
        if ((balance-a)<overdraftlimit) {
            cout<<"You have crossed overdraft limit."<<endl;
            return false;
        }
        else {
            return true;
        }
    }
};
int main () {
    string accno;
    int choice;
    float updatelimit, balance,amount;
    cout<<"Enter your balance: "<<endl;
    cin>>balance;
    cout<<"Enter your account number: "<<endl;
    cin>>accno;
    bankaccount obj( accno,balance);
    savingsaccount acc(accno,balance);
    buisnessaccount b(accno,balance);
    checkingaccount c(accno,balance);
    cout<<"Enter the amount to deposit: "<<endl;
    cin>>amount;
    obj.deposit(amount);
    b.taxdeduction();
    acc.interest();
    cout<<"Enter the amount to withdraw: "<<endl;
    cin>>amount;
    if (c.checkforoverdraft(amount)) {
        obj.withdraw(amount);
            }
            else {
                cout<<"You cannot withdraw this amount as you'll cross the overdraft limit."<<endl;
            }
    //A Customer can only deposit or withdraw from his/her accounts.
    cout<<"Would you like to freeze your account? (Enter 1 for Yes, 0 for No)"<<endl;
    cin>>choice;
    if (choice == 1) {
        obj.setFreeze(true);
    } else if (choice == 0) {
        obj.setFreeze(false);
    }
        else {
            cout<<"Please enter a valid choice.";
            }
            //a teller can deposit, withdraw or freeze accounts
            if (obj.getissfreeze()==false) {
            cout<<"Your current limit is 50k. What would you like to set your limit to?"<<endl;
    cin>>updatelimit;
    obj.setacclimit(updatelimit); 
            }
            else {
                cout<<"Account freezed. "<<endl;
            }
    //A Manager can do all of the above plus adjust account limits.

    
   





}
