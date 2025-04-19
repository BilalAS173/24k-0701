#include <iostream>
#include <string>
using namespace std;

enum StudentStatus { UNDERGRADUATE, GRADUATE, DOCTORAL };

class Student {
protected:
    string name;
    int studentId;
public:
    Student(const string& n, int id) : name(n), studentId(id) {}
    
    virtual double getTuition(StudentStatus status, int creditHours) = 0;
    
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentId << endl;
    }
    
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    GraduateStudent(const string& n, int id) : Student(n, id) {}
    
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }
    
    string getResearchTopic() const {
        return researchTopic;
    }
    
    double getTuition(StudentStatus status, int creditHours) override {
        double rate;
        switch(status) {
            case UNDERGRADUATE:
                rate = 200;
                break;
            case GRADUATE:
                rate = 300;
                break;
            case DOCTORAL:
                rate = 400;
                break;
            default:
                rate = 0;
        }
        return creditHours * rate;
    }
    
    void displayInfo() override {
        Student::displayInfo();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    Student* student = new GraduateStudent("John Doe", 1001);
    dynamic_cast<GraduateStudent*>(student)->setResearchTopic("Machine Learning");
    cout << "Tuition as Undergraduate (12 credits): $" << student->getTuition(UNDERGRADUATE, 12) << endl;
    
    cout << "Tuition as Graduate (9 credits): $" << student->getTuition(GRADUATE, 9) << endl;
    
    cout << "Tuition as Doctoral (6 credits): $" << student->getTuition(DOCTORAL, 6) << endl;

    cout << "\nStudent Information:" << endl;
    student->displayInfo();
    
    delete student;
    return 0;
}