#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printPowerOrSubsequence(string s){
    int n = s.length();
    int power_size = pow(2,n);

    for(int i = 0; i< power_size ; i++){ // 2
    string temp ="";
        for(int j = 0; j< n ; j++){ // 0 1 2
         cout<<"AND for i = "<<i<<" and j = "<<j<<" i & (1<<j) = "<<(i & (1<<j) )<<endl;
            // For every i we check if every jth bit is checked or not.
            
            if( (i & (1 << j)) != 0) {  // 2&1 , 2&2 , 2&4 (i & (1 << j))! = 0 is imp and not i&(1<<j) !=0
             //cout<<s[j];
             cout<<"AND for i = "<<i<<" and j = "<<j<<" i & (1<<j) is True"<<endl;
             temp+=s[j];
            }   
        }
        cout<<temp<<endl;
        
    }
}

int main(){
    string s;
    cin>>s;
    printPowerOrSubsequence(s);
    return 0;
}