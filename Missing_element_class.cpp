#include <iostream>
using namespace std;
int findMissingElement(int arr[], int size) {
    int n = size + 1;  
    for (int i = 1; i <= n; ++i) {
        bool found = false;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};  
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingElement = findMissingElement(arr, size);
    cout << "The missing element is: " << missingElement <<endl;

    return 0;
}
