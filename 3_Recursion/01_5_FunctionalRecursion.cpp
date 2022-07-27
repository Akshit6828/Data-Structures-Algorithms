#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Functional Recursion use case:
1) When we know that for f(n), `n` will be there but also we need answer for rest of (n-1) states.
2) Mostly used when we need to return any value from our answer.
3) We know the base case for either (n == 0) or (n == n) ;

Eg: Sum from 1 to N. F(3) = 3 + F(2)
*/

int Sum_1_to_N(int n){
    if(n  <  1)
        return 0;
    return n + Sum_1_to_N(n-1);
}
int fact(int n){
    if(n == 0) // 0! = 1
        return 1;
    return n * fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<"Sum from 1 to N using Functional Recursion = "<<Sum_1_to_N(n)<<endl;
    cout<<"Factorial N using Functional Recursion = "<<fact(n)<<endl;
    return 0;
}