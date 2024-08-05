#include <iostream>
using namespace std;

void sum(int arr[], int n) {
    int ans[100][2]; 
    int ans_size = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            for (int k = 0; k < n; k++) {
                if (arr[i] + arr[j] == arr[k]) {
                    ans[ans_size][0] = arr[i];
                    ans[ans_size][1] = arr[j];
                    ans_size++;
                }
            }
        }
    }

    for (int i = 0; i < ans_size; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}

int main() {
    int arr[] = {1, 3, 2, 6, 9, 8, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]); 
    sum(arr, size);
    return 0;
}
