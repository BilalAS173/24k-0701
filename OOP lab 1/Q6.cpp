#include <iostream>
#include <cstdio>
using namespace std;
int main () {
string stdname;
float testscores[5];
float sum=0.0, average=0.0;
cout<<"Enter the student's name and the 5 test scores: ";
cin>>stdname;
for (int i=0;i<5;i++) {
    cin>>testscores[i];
    sum+=testscores[i];
}
average=sum/5.0;
printf("The average is: %.2f",average);


}