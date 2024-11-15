#include <iostream>
using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int left, int right) {
    int pivot = arr[left];  
    int minIndex = left;   

    
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;  
        }
    }

   
    swap(arr[left], arr[minIndex]);
    
    return left;  
}


void selectionSortUsingPartition(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        
        partition(arr, i, n - 1);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    selectionSortUsingPartition(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
