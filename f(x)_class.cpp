#include<iostream>
#include<math.h>
using namespace std;
void sum(int arr[],int n,int x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i] *pow(x,i) ;
    }
    cout<<sum;
}
int  main()
{
int arr[]={2,3,4,5,6,7};
int size=sizeof(arr)/sizeof(arr[0]);
int x;
cin>>x;
sum(arr, size, x);
return 0;
}

