#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Generate all subsets

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

void makeSubsets(int ind, vector<int>& arr, vector<int> &ds, vector<vector<int>> &subsets) {
    if(ind == arr.size()){
        subsets.push_back(ds);
        return;
    }

    // Take:
    ds.push_back(arr[ind]);
    makeSubsets(ind + 1, arr, ds, subsets);
    ds.pop_back();

    // Not take:
    makeSubsets(ind + 1, arr, ds, subsets);
    
}

int main(){
    vector<int> arr = {3,2,1};
    vector<vector<int>> allPossibleSubsets;
    vector<int> ds;
    makeSubsets(0,arr,ds,allPossibleSubsets);
    printVector(allPossibleSubsets);
    return 0;
}