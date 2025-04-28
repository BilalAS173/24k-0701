#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;
};

// Function prototypes
void createDummyData();
vector<Employee> readAllEmployees();
void writeAllEmployees(const vector<Employee>& employees);
vector<Employee> findManagersWithMinYears(const vector<Employee>& employees, int minYears);
void deleteEmployeesExcept(vector<Employee>& employees, const vector<Employee>& toKeep);
void incrementIdsAndYears(vector<Employee>& employees, int idIncrement, int yearsIncrement);
void displayEmployees(const vector<Employee>& employees);

int main() {
 
    createDummyData();
  
    vector<Employee> employees = readAllEmployees();
    cout << "All Employees:\n";
    displayEmployees(employees);
    
    vector<Employee> managers = findManagersWithMinYears(employees, 2);
    cout << "\nManagers with at least 2 years service:\n";
    displayEmployees(managers);
    
    deleteEmployeesExcept(employees, managers);
    cout << "\nAfter deleting non-managers:\n";
    displayEmployees(employees);
    writeAllEmployees(employees);
    
    incrementIdsAndYears(managers, 100, 1);
    employees.insert(employees.end(), managers.begin(), managers.end());
    cout << "\nAfter adding incremented copies:\n";
    displayEmployees(employees);
    writeAllEmployees(employees);
    
    return 0;
}

void createDummyData() {
    vector<Employee> dummyData = {
        {1, "John Doe", "Manager", 3},
        {2, "Jane Smith", "Developer", 1},
        {3, "Bob Johnson", "Manager", 2},
        {4, "Alice Brown", "Designer", 4},
        {5, "Charlie Wilson", "Manager", 1}
    };
    writeAllEmployees(dummyData);
}

vector<Employee> readAllEmployees() {
    vector<Employee> employees;
    ifstream inFile("employees.txt");
    
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            Employee emp;
            
            getline(ss, token, ',');
            emp.id = stoi(token);
            
            getline(ss, emp.name, ',');
            getline(ss, emp.designation, ',');
            
            getline(ss, token, ',');
            emp.yearsOfService = stoi(token);
            
            employees.push_back(emp);
        }
        inFile.close();
    }
    return employees;
}

void writeAllEmployees(const vector<Employee>& employees) {
    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        for (const auto& emp : employees) {
            outFile << emp.id << "," << emp.name << "," 
                   << emp.designation << "," << emp.yearsOfService << "\n";
        }
        outFile.close();
    }
}

vector<Employee> findManagersWithMinYears(const vector<Employee>& employees, int minYears) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.designation == "Manager" && emp.yearsOfService >= minYears) {
            result.push_back(emp);
        }
    }
    return result;
}

void deleteEmployeesExcept(vector<Employee>& employees, const vector<Employee>& toKeep) {
    vector<Employee> newList;
    for (const auto& emp : employees) {
        for (const auto& keeper : toKeep) {
            if (emp.id == keeper.id) {
                newList.push_back(emp);
                break;
            }
        }
    }
    employees = newList;
}

void incrementIdsAndYears(vector<Employee>& employees, int idIncrement, int yearsIncrement) {
    for (auto& emp : employees) {
        emp.id += idIncrement;
        emp.yearsOfService += yearsIncrement;
    }
}

void displayEmployees(const vector<Employee>& employees) {
    cout << "ID\tName\t\tDesignation\tYears\n";
    cout << "----------------------------------------\n";
    for (const auto& emp : employees) {
        cout << emp.id << "\t" << emp.name << "\t" 
             << emp.designation << "\t\t" << emp.yearsOfService << "\n";
    }
}