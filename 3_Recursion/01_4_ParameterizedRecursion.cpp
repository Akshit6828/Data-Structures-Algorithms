#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void Sum_1_to_N(int i, int sum){
    if( i < 1){
        cout<<sum<<endl;
        return;
    }
    
    Sum_1_to_N(i-1, sum + i);
}

void factorial(int i, int fact){
    if(i < 1){
        cout<<fact<<endl;
        return;
    }
    factorial(i - 1, i * fact);
}
int main(){
    int n;
    cin>>n;
    
    cout<<"Sum from 1 to N = ";
    Sum_1_to_N(n, 0);
    cout<<"Factorial of N = ";
    factorial(n, 1);

    return 0;
}