#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string employeeID;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }
    
    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income (PKR): ";
        cin >> monthlyIncome;
    }
    
    double bonus() {
        return monthlyIncome * 12 * 0.05;
    }
    
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: PKR " << monthlyIncome << endl;
        cout << "Annual Bonus: PKR " << bonus() << endl << endl;
    }
};

class Accounts : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income (PKR): ";
        cin >> monthlyIncome;
    }
    
    double bonus() {
        return monthlyIncome * 12 * 0.05;
    }
    
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: PKR " << monthlyIncome << endl;
        cout << "Annual Bonus: PKR " << bonus() << endl << endl;
    }
};

int main() {
    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;
    
    Admin* admins = new Admin[numEmployees];
    Accounts* accounts = new Accounts[numEmployees];
    
    int adminCount = 0, accountsCount = 0;
    
    for (int i = 0; i < numEmployees; i++) {
        int dept;
        cout << "\nEmployee " << i+1 << " - Enter Department (1 for Admin, 2 for Accounts): ";
        cin >> dept;
        
        if (dept == 1) {
            admins[adminCount].getData();
            adminCount++;
        } else if (dept == 2) {
            accounts[accountsCount].getData();
            accountsCount++;
        } else {
            cout << "Invalid department! Try again." << endl;
            i--;
        }
    }
    
    cout << "\n\n--- Employee Records (Currency in PKR) ---\n";
    cout << "ADMIN DEPARTMENT:\n";
    for (int i = 0; i < adminCount; i++) {
        admins[i].displayData();
    }
    
    cout << "ACCOUNTS DEPARTMENT:\n";
    for (int i = 0; i < accountsCount; i++) {
        accounts[i].displayData();
    }
    
    delete[] admins;
    delete[] accounts;
    
    return 0;
}