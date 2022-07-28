#include<bits/stdc++.h>
#include<iostream>
using namespace std;


/* Note:
Whenever your base case return value is a part of answer, you should/can use `return`
statement in the function call */
bool checkPalindromeUsingRecursion(string s, int i, int n){

    if(s[i] != s[n - i - 1])
        return false;
    
    if(i > n/2)
        return true;
        
    return checkPalindromeUsingRecursion(s,i+1,n);
    
}

int main(){
    cout<<"Enter a string\n";
    string s;
    cin>>s;
    int len = s.length();
    bool ans = checkPalindromeUsingRecursion(s, 0 ,len);
    if(ans) 
        cout<<"true"<<endl;
    else 
        cout<<"false"<<endl;
    
    return 0;
}