#include<iostream>
using namespace std;
int main(){
    int velocity;
    cout<<"enter the value of velocity of ball: ";
    cin>>velocity;
    int dip=0;
    while(velocity>0){
        velocity=velocity/2;
        dip=dip+1;

    }
    cout<<"total time taken by ball to stop:"<<dip;
    return 0;
}