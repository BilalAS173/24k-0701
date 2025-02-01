#include <iostream>
using namespace std;
int main (int argv, char* argv[]) {
    int sum=0;
int array[5]={2,4,6,8,10};
int *arr=array;
for (int i=0;i<5;i++) {
    sum+=*arr[i];
}
cout<<"The sum is: "<<sum<<endl;
}