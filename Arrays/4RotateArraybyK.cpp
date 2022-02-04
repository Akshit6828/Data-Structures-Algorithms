#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Rotating Array Anti Clock Wise
void reverseArr(std::vector<int> &arr, int low, int high){
	while(low< high){
swap(arr[low], arr[high]);
low++;
high--;
}
}
void leftRotate(std::vector<int> &arr, int k){ // TC: O(N) , SC: O(1)
	reverseArr(arr, 0, k-1);
	reverseArr(arr, k, arr.size()-1);
	reverseArr(arr, 0, arr.size() -1);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    int val;
    cin>>val;
    leftRotate(arr,val);
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}