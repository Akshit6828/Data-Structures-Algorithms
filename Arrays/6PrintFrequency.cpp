#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void printFreq(vector<int> &x){
    int count = 1;
    int i = 0;
    int sz = x.size();
    
    for(int i = 1; i<sz; i++){
        if(x[i] == x[i-1])
            count++;
        else{
            cout<<x[i-1]<<" : "<<count<<endl;
            count = 1;
        }
    }
    // If arr.size() == 1 or last element != second last element
    if(sz ==1 || x[sz -1 ]!=x[sz -2])
        cout<<x[sz-1] << " : 1"<<endl;
    
    
    

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    printFreq(arr);
    return 0;
}