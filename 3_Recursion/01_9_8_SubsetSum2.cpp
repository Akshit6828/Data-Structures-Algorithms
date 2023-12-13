#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Problem:
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
void printVector(vector<vector<int>> vt){
    for(int i = 0; i < vt.size(); i++){
        cout<<"[ ";
        for(int j = 0; j < vt[i].size(); j++)
            cout<<vt[i][j]<<" ";
        cout<<"]";
        if(i!= vt.size() - 1) cout<<endl;
    }
}

void SubsetSum2(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &subsequences){

    // Here no need to write a base case as the inner loop will run only till (arr.size() - 1) and at max,the recursion will go till depth of n.
    // Thus here there was no need of writing a base case.
    
    subsequences.push_back(ds); // Pushing the current ds as at every recursion call, we are adding some value to the ds which makes this subsequence a unique.

    for(int  i = ind; i< arr.size(); i++){

        if(i > ind && arr[i] == arr[i-1]) // Ignoring duplicates if found from (ind + 1) till N.
            continue;

        ds.push_back(arr[i]); // Pushing the unique current arr[i] into the ds
        SubsetSum2(i+1,arr,ds,subsequences);
        ds.pop_back(); // Popping out for trying other (i+1 to n-1) combinations
    }
}


int main(){
    vector<int> arr = {3,1,3,3,5};
    vector<int> ds;
    vector<vector<int>> uniqueSubsequences;

    sort(arr.begin(), arr.end());
    SubsetSum2(0, arr,ds,uniqueSubsequences);
    printVector(uniqueSubsequences);
    return 0;
}