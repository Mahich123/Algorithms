#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {-1,2,4,-3,5,2,-5,2};

    int max_so_far = 0, sum;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
            sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            max_so_far = max(max_so_far,sum);
        }
    }

    cout << max_so_far;
}
