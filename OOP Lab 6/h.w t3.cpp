#include <iostream>
using namespace std;
class Student {
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}

    void showStudentDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

class Marks : public Student {
protected:
    int subject1, subject2, subject3;

public:
    Marks(string n, int r, int m1, int m2, int m3) 
        : Student(n, r), subject1(m1), subject2(m2), subject3(m3) {}

    void showMarks() {
        cout << "Marks in Subject 1: " << subject1 << endl;
        cout << "Marks in Subject 2: " << subject2 << endl;
        cout << "Marks in Subject 3: " << subject3 << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int r, int m1, int m2, int m3) 
        : Marks(n, r, m1, m2, m3) {}
    void showResult() {
        int total = subject1 + subject2 + subject3;
        float average = total / 3.0;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    Result student1("Harry", 123, 67, 90, 70);
    cout << "Student Details:\n";
    student1.showStudentDetails();
    cout << "\nMarks Obtained:\n";
    student1.showMarks();
    cout << "\nFinal Result:\n";
    student1.showResult();
    return 0;
}
