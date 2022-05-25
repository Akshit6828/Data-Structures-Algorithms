#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> mergeArrays(vector<int> v1, vector<int> v2){ // O(n + m)
    int sz1 = v1.size();
    int sz2 = v2.size();
    int i = 0, j = 0;

    vector<int> merged;
    int lst = 0;
    while(i < sz1 && j < sz2){
        // if(i > 0 && v1[i] == v1[i-1]){ // For duplicates
        //     i++;
        //     continue;
        // }
        if(v1[i] <= v2[j]){
            merged.emplace_back(v1[i]);
            i++;
        }
        else{
            merged.emplace_back(v2[j]);
            j++;
        }
        
    }
    while(i < sz1) {
        merged.emplace_back(v1[i]);
        i++;
    }
    while ( j< sz2){
        merged.emplace_back(v2[j]);
        j++;
    }
    
    return merged;
}

int main(){
    
    vector<int> v1 = {6,3,2,5,9};
    vector<int> v2 = {63,0,1,55,2,7};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> ans = mergeArrays(v1,v2);

    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}