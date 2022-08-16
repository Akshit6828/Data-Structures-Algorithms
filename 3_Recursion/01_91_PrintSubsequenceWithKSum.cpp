#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printSubsequenceWithKSum(int ind, vector<int> &arr , int sum, vector<int> &ds, int n, int K){
    if(ind == n){ // Note: This condition is important first, as we need a stopping conditon for the program as if index == n-1, then we cant make any furter subsequence.
        if(sum == K){
            for(auto it: ds) 
                cout<<it<<" ";
            cout<<endl;
        }
        return; // Important to add else the base conditon will not be able to return back and will lead to infinite loop
    }

    // Take
    ds.push_back(arr[ind]);
    sum+=arr[ind];

    printSubsequenceWithKSum(ind +1, arr,sum,ds,n,K);

    // Remove or back-track
    ds.pop_back();
    sum-=arr[ind];

    // Not Take
    printSubsequenceWithKSum(ind +1, arr,sum,ds,n,K);
}
int main(){
    int n, sum;
    cin>>n>>sum;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) 
        cin>>arr[i];

    vector<int> ds;
     cout<<"Subsequence with Sum = "<<sum<<" are:\n";

    printSubsequenceWithKSum(0, arr,0,ds,n, sum);
    return 0;
}