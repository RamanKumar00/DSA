#include<iostream>
using namespace std;
int Binarysearch(int arr[],int n,int key)
{
    int start=0,end=n-1,mid;
    while (start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
            break;
        }
        else if(arr[mid]<key)
        {
            start=mid+1;
        }
        else
        {
           end=mid-1;
        }
}
    return -1;
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the elements to find: ";
    cin>>key;
    cout<<Binarysearch(arr,n,key);
    return 0;
}