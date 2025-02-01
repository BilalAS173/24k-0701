#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Subject {
    string subject_name;  // Name of the subject
};

struct Student {
    int student_id;          // ID of the student
    vector<Subject> subjects;  // Vector to store multiple subjects
};

int main() {
    int n;  // Number of students
    cout << "Enter the number of students: ";
    cin >> n;
    
    vector<Student> students(n);  // Vector to hold n students

    // Taking input for each student
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter ID for student " << i + 1 << ": ";
        cin >> students[i].student_id;

        int num_subjects;
        cout << "Enter number of subjects for student " << i + 1 << ": ";
        cin >> num_subjects;

        // Taking input for each subject for the current student
        for (int j = 0; j < num_subjects; ++j) {
            Subject temp_subject;
            cout << "Enter name of subject " << j + 1 << ": ";
            cin >> temp_subject.subject_name;
            students[i].subjects.push_back(temp_subject);  // Adding subject to the student's subjects list
        }
    }

    // Printing the student details
    cout << "\nStudent Details:\n";
    for (const auto& student : students) {
        cout << "Student ID: " << student.student_id << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.subject_name << " ";
        }
        cout << "\n";
    }

    return 0;
}
