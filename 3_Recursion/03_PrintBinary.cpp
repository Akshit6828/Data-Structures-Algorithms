#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 

 // Decimal to binary conversion:
 // We keep dividing the num by 2 and keep storing the remainder.
void binary(int n){

    if(n == 0)
        return;
    binary(n/2);
    cout<<n%2<<" ";
}
int main(){
    binary(6);
    return 0;
}