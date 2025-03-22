#include <iostream>
#include <vector>
#include <string>
using namespace std;
class person {
protected:
    string name;
    string id;
    string address;
    int phoneno;
    string email;
public:
    person(string n, string id, string a, int b, string c): name(n), id(id), address(a), phoneno(b), email(c) {}
    string getname() {
        return name;
    }
    virtual void displayinfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number: " << phoneno << endl;
        cout << "Email: " << email << endl;
    }
    void updateinfo(string n, string id, string a, int b, string c) {
        name = n;
        this->id = id;
        address = a;
        phoneno = b;
        email = c;
    }
};

class professor: public person {
protected:
    string department;
    int coursestaught;
    float salary;
public:
    professor(string d, int e, float f, string n, string id, string a, int b, string c): department(d), coursestaught(e), salary(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursestaught << endl;
        cout << "Salary: " << salary << endl;
    }
};

class student: public person {
protected:
    int enrollmentyear;
    int coursesenrolled;
    float gpa;
public:
    student(int d, int e, float f, string n, string id, string a, int b, string c): enrollmentyear(d), coursesenrolled(e), gpa(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Enrollment year: " << enrollmentyear << endl;
        cout << "Courses enrolled: " << coursesenrolled << endl;
        cout << "GPA: " << gpa << endl;
    }
};

class staff: public person {
protected:
    string department;
    string position;
    float salary;
public:
    staff(string d, string e, float f, string n, string id, string a, int b, string c): department(d), position(e), salary(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};
class course {
protected:
    string id;
    int credits;
    string instructor;
    string name;
    string schedule;
    vector<student> students;
public:
    course(string i, int b, string c, string n, string s): id(i), credits(b), instructor(c), name(n), schedule(s) {}
    void registerStudent(student std) {
        students.push_back(std);
        cout << "Student " << std.getname() << " registered successfully for " << name << " by " << instructor << "." << endl;
    }
    void calcGrades() {
        cout << "Grade calculation for course " << name << endl;
    }
    void displayCourseInfo() {
        cout << "Course ID: " << id << endl;
        cout << "Course Name: " << name << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Registered Students: " << students.size() << endl;
    }
};

int main() {
    student s1(2021, 5, 3.8, "Alice", "S1238", "123 Main St", 5591234, "alice@uni.com");
    professor p1("Computer Science", 3, 75000, "Dr. Smith", "P456", "456 Elm St", 5555678, "smith@uni.com");
    staff st1("Accounts", "Manager", 50000, "David", "ST789", "789 Oak St", 5559101, "xyz@uni.com");
    course c1("CS101", 3, "Mr. Harry", "Programming Fundamentals", "Mon/Wed/Thur 10:00 AM");
    s1.displayinfo();
    p1.displayinfo();
    st1.displayinfo();
    c1.registerStudent(s1);
    c1.displayCourseInfo();
    c1.calcGrades();

    return 0;
}