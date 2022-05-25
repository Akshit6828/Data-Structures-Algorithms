#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void mergeOneArrayAndMakeSorted(vector<int> &x, int low,  int high, int mid){
    vector<int> v1, v2;
    for(int i = 0; i<=mid;i++)
        v1.push_back(x[i]);

    for(int i = mid+1; i<x.size();i++)
        v2.push_back(x[i]);  
    
    int index = 0;
    int  i = 0, j = 0;
    int sz1 = v1.size();
    int sz2 = v2.size();
    while(i < sz1 && j < sz2){

        if(v1[i] <= v2[j]){
            x[index] = v1[i];
            i++;
        }
        else{
            x[index] = v2[j];
            j++;
        }
        index++;
        
    }
    while(i < sz1) {
        x[index] = v1[i];
        i++;
        index++;
    }
    while ( j< sz2){
        x[index] = v2[j];
        j++;
        index++;
    }

}

void PrintVector(vector<int> &arr){
    cout<<"Array is :\n";
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout <<"\n";
}
int main(){
    vector<int> x = {5,6,9,10,19,25,2,3,4};
    PrintVector(x);
    mergeOneArrayAndMakeSorted(x, 0, x.size() -1, 5);
    PrintVector(x);

    return 0;
}