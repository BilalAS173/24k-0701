#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int empId;
    double salary;
public:
    virtual void getdata() = 0; 
    virtual void displaydata() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Base Salary: " << salary << endl;
    }
    virtual double bonus() = 0; 
    virtual ~Person() {}
};

class Admin : virtual public Person {
protected:
    double adminBonus;
public:
    void getdata() override {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter base salary: ";
        cin >> salary;
        cout << "Enter admin bonus percentage: ";
        cin >> adminBonus;
    }
    
    double bonus() override {
        return salary * adminBonus / 100;
    }
};

class Account : virtual public Person {
protected:
    double accountBonus;
public:
    void getdata() override {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter base salary: ";
        cin >> salary;
        cout << "Enter account bonus percentage: ";
        cin >> accountBonus;
    }
    
    double bonus() override {
        return salary * accountBonus / 100;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter base salary: ";
        cin >> salary;
        cout << "Enter admin bonus percentage: ";
        cin >> adminBonus;
        cout << "Enter account bonus percentage: ";
        cin >> accountBonus;
    }
    
    void displaydata() override {
        Person::displaydata();
        cout << "Admin Bonus: " << adminBonus << "%" << endl;
        cout << "Account Bonus: " << accountBonus << "%" << endl;
    }
    
    double bonus() override {
        return salary * (adminBonus + accountBonus) / 100;
    }
};

int main() {
    Person* employees[3];
    employees[0] = new Admin();
    employees[1] = new Account();
    employees[2] = new Master();
    for(int i = 0; i < 3; i++) {
        cout << "\nEnter details for employee " << i+1 << ":" << endl;
        employees[i]->getdata();
    }

    for(int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i+1 << " details:" << endl;
        employees[i]->displaydata();
        cout << "Total Bonus: " << employees[i]->bonus() << endl;
    }
    for(int i = 0; i < 3; i++) {
        delete employees[i];
    }
    
    return 0;
}