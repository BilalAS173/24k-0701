#include<iostream>
using namespace std;
float function (float *array) {
float sum=0.0;
for (int i=0;i<20;i++) {
  sum+=array[i];
}
return sum;
}
int main (int argc, char* argv[]) {
float array[20]={2.5, 6.7, 8.8, 9.9, 10.0, 7.7, 2.2, 1.1, 3.3, 4.6, 2.9, 1.8, 1.1, 9.9, 10.9, 11.7, 15.5, 20.8, 18.4, 7.6};
float sum;
sum=function(array);
cout<<"Sum of all 20 elements is: "<<sum<<endl;
}