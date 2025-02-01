#include <iostream>
#include <cstring> 
using namespace std;
struct employee {
    int employee_id;
    string name;
    int salary;
};
struct organisation {
string organisation_name;
string organisation_number;
struct employee emp;
} org;
int main () {
org.organisation_name="NU-FAST";
org.organisation_number="NUFAST123ABC";
org.emp.employee_id=127;
org.emp.salary=40000;
org.emp.name="Linus Sebastian";
cout<<"The Size of structure organisation: "<<sizeof(struct organisation)<<endl;
cout<<"Organisation Name : "<<org.organisation_name<<endl;
cout<<"Organisation Number: "<<org.organisation_number<<endl;
cout<<"Employee id :"<<org.emp.name<<endl;
cout<<"Employee name: "<<org.emp.name<<endl;
cout<<"Employee salary: "<<org.emp.salary<<endl;
return 0;
}
