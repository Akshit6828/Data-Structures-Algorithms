#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Fibonacci series = 0 1 1 2 3 5 8 13 .... 
/*
We know that fibo(0) = 0, fibo(1) = 1;
1) So for computing, fibo(n) we can come from n to 1
2) As the return value is a part of answer, so we can use return statement for function calls.
*/


// TC: Similar to O(2^n) as for every N, we are calling 2 calls. and for 2^N is calling.

int fibo(int n){
    if(n < 2)
        return n;
    
    return fibo(n-1) + fibo(n-2); // Multiple recursion calls execute.
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n);  
    return 0;
}