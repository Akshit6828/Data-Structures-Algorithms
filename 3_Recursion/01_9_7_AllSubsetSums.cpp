#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Generate all subsets
*/
void printVector(vector<int> vt){
    for(int i = 0; i < vt.size(); i++){
        cout<<"[ ";
            cout<<vt[i]<<" ";
        cout<<"]";
        cout<<endl;
    }
}

void generateSubsetSums(int ind, vector<int>& arr, int sum, vector<int> &subsets) {

    if(ind == arr.size()){
        subsets.push_back(sum);
        return;
    }

    // Take: Updating the sum = sum + arr[ind]
    generateSubsetSums(ind + 1, arr, sum + arr[ind], subsets);

    // Not take: Not updating the sum
    generateSubsetSums(ind + 1, arr, sum, subsets);
    
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> subsetSums;
    int sum = 0;
    generateSubsetSums(0, arr, sum, subsetSums);
    sort(subsetSums.begin(), subsetSums.end());
    printVector(subsetSums);

}