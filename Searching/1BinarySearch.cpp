#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isPresent(std::vector<int> arr, int value){
int low  = 0,high = arr.size()-1;
	while(low<=high){
		int mid = (low + high)/2;
		if(arr[mid] == value)
			return true;
		if(value < arr[mid])
			high = mid-1;
		if(value > arr[mid])
			low =mid+1;
			
}
return false;
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
    cout<<isPresent(arr,val);
    
    return 0;
}