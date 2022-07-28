#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void ReverseArrayUsing_2_Pointers(int arr[], int left, int right){ // TC: O(n/2) SC: O(n/2)
    if(left > right)
    return;

    swap(arr[left], arr[right]);
    ReverseArrayUsing_2_Pointers(arr, left+1, right - 1);
}

void ReverseArrayUsing_1_Pointer(int arr[], int i, int n){ // TC: O(n/2) SC: O(n/2)
    // Important to use >= as else it will fail for n = even.
    // Say n = 10,  and n/2 = 5, so at n == 5, it would again swap (arr[5], arr[6]) which would lead to reswapping from the center.
    // For better understanding try example: n = 6, 1 2 3 4 5 6
    if(i >= n/2) // We only need to traverse half of array as we swap its compliment from end at every call.
        return;
    
    swap(arr[i], arr[n-i-1]); // (i)th index from beginning = (n-i-1) index from end.
    ReverseArrayUsing_1_Pointer(arr, i+1,n);
}

void printArray(int arr[], int n){
     for(int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int x[n];
    for(int i = 0; i < n; i++)
    cin>>x[i];

    ReverseArrayUsing_2_Pointers(x, 0, n-1);
    printArray(x, n); 
    cout<<endl;
    ReverseArrayUsing_1_Pointer(x,0,n);
    printArray(x,n);
    return 0;
}