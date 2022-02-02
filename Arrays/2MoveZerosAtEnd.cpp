#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void moveZeroes(std::vector<int>& arr) {
        int lastUnique =0;
	    for(int i = 0; i<arr.size();i++){
		    if(arr[i] !=0){
			    swap(arr[i], arr[lastUnique]);
			    lastUnique++;
            }
        }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    moveZeroes(arr);
    
    return 0;
}