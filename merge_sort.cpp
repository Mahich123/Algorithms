/*Merge sort pseudocode
    merge_sort(A,left, right)
    if left >= right return;
    else
        middle = b(left+right)/2
        merge_sort(A,left, middle)
        merge_sort(A,middle+1, right)
        merge(A,left,middle,right)

*/

/*
    Merge(A,left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    create array L[n1], R[n2]
    for i => 0 to n1 - 1 do L[i] => A[left + i]
    for j => 0 to n2 - 1 do R[j] => A[mid + j]
    k => i => j => 0
    while i < n1 & j < n2
        if L[i] < R[j]
            A[k++] => L[i++]
        else
            A[k++] => R[j++]
    while i < n1
      A[l++] => L[i++]
    while j < n2
      A[k++] => R[j++]
*/


#include<bits/stdc++.h>
using namespace std;

void merge_function(vector<int> &v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int>L(n1),R(n2);

    for(int i = 0; i < n1; i++) {
        L[i] =v[left+i];
    }

    for(int j = 0; j < n1; j++) {
        R[j] =v[mid+j+1];
    }



    int i ,j,k;
    i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            v[k++] =  L[i];
            i++;
        }
        else
        {
            v[k++] = R[j];
            j++;
        }
    }

    while(i < n1)
    {
        v[k++] = L[i++];
    }
    while(j < n2)
    {
        v[k++] = R[j++];
    }

}

void merge_sort(vector<int> &v, int left, int right) {
    int mid;
    if(left >= right)
        return;
    else {
        mid = (left+right)/2;
        merge_sort(v,left,mid);
        merge_sort(v, mid+1, right);
        merge_function(v,left,mid,right);
    }
}

int main() {
    vector<int> v;
    int n, input;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    merge_sort(v,0,n-1);

    for(int val: v)
        cout<<val<<" ";

}
