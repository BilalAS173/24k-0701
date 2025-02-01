#include <iostream>
using namespace std;
void* add (void* array) {
 int *arr=(int*)array;
for (int i=0;i<5;i++) {
cout<<"Enter value "<<i+1<<":"<<endl;
cin>>arr[i];
 }
    int result=0;
    for(int i=0;i<5;i++){
    result+=arr[i];
    }
    void *ptr=(void*)&result;
    return ptr;
}
int main (int argc, char* argv[]) {
    //int array[5]={1,2,3,4,5};
    int array[5];
    void *ptr=(void*)array;
    int result=*(int*)add(ptr);
    cout<<"The result after addition is: "<<result<<endl;
}