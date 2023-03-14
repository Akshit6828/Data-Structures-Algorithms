#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void display_binary(int n){
    cout<<"The Binary Representation of "<<n<<" is :";
    string res = ""; // 5 2 1 0
    if(n == 0)
        res+="0";
        
    while(n>0){
        if(n&1)
            res+="1";
        else
            res+="0";
        n=n>>1; // n = n/2;
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;
}

int main(){    
    display_binary(9);
    display_binary(19);
    display_binary(1);
    display_binary(0);
    return 0;
}