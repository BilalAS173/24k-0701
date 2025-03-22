#include <iostream>
#include <vector>
#include <string>
using namespace std;
class account {
protected:
    string accno;
    double balance;
    string acchname;
    string acctype;
    vector<string> transactionHistory; // To store transaction history
public:
    account(string a, double b, string ac, string act)
        : accno(a), balance(b), acchname(ac), acctype(act) {}

    void deposit(double amount) {
        balance += amount;
        string transaction = "Deposited: PKR " + to_string(amount) + " to account " + accno + " (" + acchname + ")";
        transactionHistory.push_back(transaction); 
        cout << transaction << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds in account " << accno << " (" << acchname << ")" << endl;
            return;
        }
        balance -= amount;
        string transaction = "Withdrew: PKR " + to_string(amount) + " from account " + accno + " titled " + acchname;
        transactionHistory.push_back(transaction); 
        cout << transaction << endl;
    }

    virtual void calcinterest() {
        //  (can be overridden by derived classes)
    }

    void printStatement() const {
        cout << "Account Statement for " << acchname << " (" << accno << "):" << endl;
        cout << "Current Balance: PKR " << balance << endl;
        cout << "Transaction History:" << endl;
        for (const string& transaction : transactionHistory) {
            cout << " - " << transaction << endl;
        }
    }
};
class savingacc : public account {
protected:
    float interestrate = 0.1;
    double minbalance = 1000;

public:
    savingacc(string a, double b, string ac, string act)
        : account(a, b, ac, act) {}

    void checkforminbalance(double amount) {
        if ((balance - amount) >= minbalance) {
            withdraw(amount);
        } else {
            cout << "Transaction cannot be processed as you have insufficient balance." << endl;
        }
    }

    void calcinterest() override {
        double interest = balance * interestrate;
        balance += interest;
        string transaction = "Interest added: PKR " + to_string(interest) + " to account " + accno + " (" + acchname + ")";
        transactionHistory.push_back(transaction); 
        cout << transaction << endl;
    }
};

class checkingacc : public account {
public:
    checkingacc(string a, double b, string ac, string act)
        : account(a, b, ac, act) {}
};

class fixeddepositacc : public account {
public:
    fixeddepositacc(string a, double b, string ac, string act)
        : account(a, b, ac, act) {}

    void withdraw(double amount) override {
        cout << "Withdrawal not possible as it's a fixed deposit account." << endl;
    }

    void calcinterest() override {
        double interest = balance * 0.2; 
        balance += interest;
        string transaction = "Interest added: PKR " + to_string(interest) + " to account " + accno + " (" + acchname + ")";
        transactionHistory.push_back(transaction); 
        cout << transaction << endl;
    }
};

int main() {
    checkingacc c("13587", 1000, "Harry", "Checking");
    fixeddepositacc f("67899", 5000, "David", "Fixed Deposit");
    savingacc s("54321", 2000, "Smith", "Savings");

    account* a = &c;
    a->deposit(1500);
    a->withdraw(167);
    a->printStatement(); // Print statement for checking account

    cout << "\n---------------------------------\n";

    a = &s;
    a->deposit(5000);
    a->withdraw(1000);
    a->calcinterest();
    a->printStatement(); // Print statement for savings account

    cout << "\n---------------------------------\n";

    a = &f;
    a->deposit(1000);
    a->withdraw(500); // Withdrawal not allowed
    a->calcinterest();
    a->printStatement(); // Print statement for fixed deposit account

    return 0;
}
