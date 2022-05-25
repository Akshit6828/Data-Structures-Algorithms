#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> IntersectionOfTwoSortedArrays(vector<int> v1, vector<int> v2){ // O(n + m)
    int sz1 = v1.size();
    int sz2 = v2.size();
    int i = 0, j = 0;

    vector<int> merged;
    int lst = 0;
    while(i < sz1 && j < sz2){
         if(i > 0 && v1[i] == v1[i-1]){ // For duplicates.
         // Skipping i as this element is already taken
             i++;
             continue;
        }
        if(v1[i] < v2[j]){
            i++;
        }
        else if(v1[i] > v2[j]){
            j++;
        }
        else{
            merged.emplace_back(v2[j]);
            i++;
            j++;
        }
        
    }
  
    return merged;
}

void PrintVector(vector<int> &arr){
    cout<<"Array is :\n";
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout <<"\n";
}

int main(){
    vector<int> v1 = {6,3,2,5,9};
    vector<int> v2 = {63,0,1,55,2,7};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    PrintVector(v1);
    PrintVector(v2);
    
    vector<int> intersected = IntersectionOfTwoSortedArrays(v1,v2);
    PrintVector(intersected);
    return 0;
}