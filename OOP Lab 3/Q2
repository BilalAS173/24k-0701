#include<iostream>
#include<cstdlib>
using namespace std;

class date {
    public:
    int day;
    int month;
    int year;

    void displaydate () {
        cout << "Today's date is: " << day << "/" << month << "/" << year << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: ./program_name DD MM YYYY" << endl;
        return 1;
    }
    
    date d1;
    d1.day = stoi(argv[1]);
    d1.month = stoi(argv[2]);
    d1.year = stoi(argv[3]);
    
    d1.displaydate();
    
    return 0;
}
