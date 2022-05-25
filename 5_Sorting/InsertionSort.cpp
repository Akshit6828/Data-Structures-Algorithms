#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define deb(x) cout<<#x<<" = "<<x<<endl;

void InsertionSort(vector<int> &x){

    for(int i = 1; i< x.size(); i++){
        int cur_val = x[i];
        int index = i -1;
        // Note: DONT use x[index] >= cur_val else it gonna disturb the stability of sorting algo of insertion sort.
        deb(cur_val);
        while(index >=0 && x[index] > cur_val){
            x[index +1] = x[index];
            cout<<"Shifted "<<x[index] <<" from "<<index <<" to "<<index + 1 <<"\n"; 
            cout<<"index --"<<endl;
            index--;
            deb(index);

        }
        // assigning this at index + 1 as index will be having a value smaller than cur_val;
        x[index + 1] = cur_val;
        cout<<"Placed "<<cur_val<<" at "<<index + 1 <<" index" <<"\n"; 
        
        

    }
}
int main(){
    vector<int> x = {5,3,6,9,45,2,3,56};

    cout<<"Array is :\n";
    for(auto i: x){
        cout<<i<<" ";
    }
    cout <<"\n"; 
    
    partial_sort(x.begin(), x.begin() + 5, x.end()); // sprts in the partial manner
    // nlogk
    //InsertionSort(x);
    for(auto i: x){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}