#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int JOS(int n, int k){
    if(n == 1)
        return 0;
    else
        return (JOS(n - 1, k) + k )%n;
}

int main(){
    
    int n, k;
    cin>>n>>k;
    cout<< JOS(n,k);
    // cout<< JOS(n,k); + 1 for 1 based indexing.
    return 0;
}