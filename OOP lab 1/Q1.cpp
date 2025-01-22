#include<iostream>
using namespace std;
float function (float *array) {
float high=0.0, secondhigh=0.0;
int index;
for (int i=0;i<20;i++) {
    if (array[i]>high) {
        high=array[i];
        index=i;
    }
   }
    array[index]=-1;
    for (int i=0;i<20;i++) {
        if (array[i]>secondhigh) {
        secondhigh=array[i];
    }
    }
    return secondhigh;
}
int main (int argc, char* argv[]) {
float array[20]={2.5, 6.7, 8.8, 9.9, 10.0, 7.7, 2.2, 1.1, 3.3, 4.6, 2.9, 1.8, 1.1, 9.9, 10.9, 11.7, 15.5, 20.8, 18.8, 7.6};
float high, secondhigh;
secondhigh=function(array);
cout<<"Second highest element is: "<<secondhigh<<endl;
}