#include <iostream>
#include <cstring> 
using namespace std;
struct N {
    string name;
    int id;
};
void printpersons(N persons[], int n) {
    for (int i=0;i<n;i++) {
        cout<< "ID: " << persons[i].id << endl;
        cout<<"Name: " << persons[i].name << endl;
    }
}
void bubblesortbyid(N persons[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (persons[j].id > persons[j+1].id) {
         swap(persons[j], persons[j+1]);
            }
        }
    }
}
void bubblesortbyname(N persons[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <n-i-1; j++) {
            if (persons[j].name > persons[j + 1].name) {
                swap(persons[j], persons[j + 1]);
            }
        }
    }
}
int main() {
    int num;
    cout << "Enter the number of persons: ";
    cin >> num;
    N persons[num]; 

    for (int i = 0; i<num; ++i) {
        cout << "\nEnter details for person "<<i+1<<":\n";
        cout << "ID: ";
        cin >> persons[i].id;
        cout << "Name: ";
        cin >> persons[i].name;
    }
    bubblesortbyid(persons, num);
    cout<< "\nSorted by ID:\n";
    printpersons(persons, num);
    bubblesortbyname(persons, num);
    cout<<"\nSorted by Name:\n";
    printpersons(persons, num);

    return 0;
}
