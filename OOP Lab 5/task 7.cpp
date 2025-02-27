#include <iostream>

using namespace std;
class student {
private:
const string rollnumber;
public:
student (string n): rollnumber(n) {}
string getrollnumber () {
    return rollnumber;
}

};
int main () {
    string stdrollno;
    cout<<"Enter the student's roll number: "<<endl;
    cin>>stdrollno;
    student std(stdrollno);
    cout<<"The student's roll number is: "<<std.getrollnumber()<<endl;
    
}