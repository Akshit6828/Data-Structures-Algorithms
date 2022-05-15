#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// We multiple n by 2 and we increment answer by 1.
// Thus this is nature of log.
int f1(int n){ // Returns floor of log2(n). 
// Floor of log2(n) is the largest power of 2 that is LESS than or equal to n.
// Here -> Log(16)  = Log(17) ... upto Log(24) = 4
    if(n == 1)
        return 0;
    return 1 + f1(n/2);
}

int f2(int n){ // Returns floor of log3(n).
// Floor of log3(n) is the largest power of 3 that is LESS than or equal to n.
// Here -> Log(27)  = 
    if(n<3)
        return 0;
    return 1 + f2(n/3);
}
int main(){
    cout<<f1(16)<<endl;
    cout<<f1(24)<<endl;

    cout<<f2(27)<<endl;
    cout<<f2(81)<<endl;
    return 0;
}