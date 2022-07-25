#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void subset(string s, string cur = "", int i = 0){

    // Base case if ith char = s.lenght()
    // here we wont include the ith char as it would be SEGMENT Fault
    // So it can be our base case
    if(i == s.length()){
        cout<<cur<<endl;
        return;
    }

    subset(s,cur,i+1); // Not including the current char and moving to next index
    subset(s,cur + s[i] , i+1); //including the current char and moving to next char
}

int main(){
    subset("abc");
    return 0;
}