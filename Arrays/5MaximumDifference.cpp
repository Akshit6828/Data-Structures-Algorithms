#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int maxDiff(vector<int> &arr){

    int maxD = arr[1] - arr[0];
    int minVal = arr[0];
    for(int i = 1; i<arr.size(); i++){
        if(arr[i]>=0)
            maxD= max(maxD, arr[i] - minVal );
        else
            maxD= max(maxD, minVal - arr[i]  );
        
        minVal = min(minVal, arr[i]);
    }
    return maxD;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Max Diff = "<<maxDiff(arr);
    return 0;
}