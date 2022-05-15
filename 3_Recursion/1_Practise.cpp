#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Output: 1 2 1 3 1 2 1
int fun(int n){
    if(n == 0)
        return 0;
    fun(n-1);
    cout<<n<<" ";
    fun(n-1);
}
int main(){
    fun(3);
    return 0;
}