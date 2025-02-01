#include <iostream>
#include <cstring> 
using namespace std;

void resizearray(int*& ptr, int& size, int newsize) {
    int* newptr = new int[newsize];
    memcpy(newptr, ptr, size * sizeof(int));
    delete[] ptr;
    ptr=newptr;
    size=newsize;
}

int main() {
    int* ptr = new int[5];
    int size=5, count=0, num;
    do {
        cout << "Enter a number (enter a negative number to stop): ";
        cin >> num;
        if (num >= 0) {
            ptr[count] = num;  
            count++;  
        
            if (count>=size) {
            resizearray(ptr, size, size * 2);  
            }
        }
    } while (num >= 0);  

    resizearray(ptr, size, count);
    cout << "Final array size: " << size << endl;

    delete[] ptr;

    return 0;
}
