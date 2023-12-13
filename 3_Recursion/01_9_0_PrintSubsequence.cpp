#include<bits/stdc++.h>
#include<iostream>

#define deb(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

/*
Problem: Print all subsequence of a given array
We have 2 choices:
1) Either to "TAKE" the current index element in our data structure.
2) Either to "NOT TAKE" the current index element and move to next element.

Base Case Deduction:
We keep have these both choices until we reach the index from which it is impossible to take choice.
So we keep base case as: if(cur_ind == n) // N is non-exisiting index in an array of size n which follows 0 based indexing.
We choose this base case as for this case, we know that we are not going to have any choice, just we need to return the desired answer made till here.
*/


vector<vector<int>> generateSubsequences(int cur_ind, vector<int> &arr, int n , vector<int> &ds, vector<vector<int>> &subsequences){

    if(cur_ind == n){
        subsequences.push_back(ds);
        return subsequences;
    }
    // Choice 1: TAKE
    ds.push_back(arr[cur_ind]);
    generateSubsequences(cur_ind+1,arr,n,ds, subsequences);

    // Choice 2: NOT TAKE
    // Back-tracking
    ds.pop_back(); // Popping back so that the ds could come back to the same state which was before the "TAKE - STATE"
    generateSubsequences(cur_ind+1,arr,n,ds, subsequences); 

    return subsequences; // return the final ds after both the choices are performed.
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    // vector<int> arr = {1,2,3};
    // int n = 3;
    
    vector<int> ds;
    vector<vector<int>> container; 
    vector<vector<int>> subsequences = generateSubsequences(0,arr,n,ds,container);

    for(auto sequence: subsequences){
        for(auto element: sequence)
            cout<<element<<" ";
        cout<<endl;
    }
    return 0;
}