#include<iostream>
using namespace std;
int main()
{
    int arr={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"size of array is: "<<n<<endl;
    int key;
    cin>>key;
    int i=0;
    while(i<n)
    {
        if(key==arr[i])
        {
            return 1;
        
        }
    }
    if(i==n)
    {
        cout<<"not found";
    }
    

}