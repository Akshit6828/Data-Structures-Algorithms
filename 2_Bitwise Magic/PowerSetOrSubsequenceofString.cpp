#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Idea: Binary representation form 0 to 2^n-1 would be having all representation of weither to take/not-take an index
Eg:
str = "ab", n = 2
So, power_Set(2^n - 1) = 4
Thus, binary representation of 0 - 3 is:
 a b
 ___
 0 0 ==> prints ""
 0 1 ==> prints "b"
 1 0 ==> prints "a"
 1 1 ==> prints "ab"

 How to map these set bits to actual array/string indexes?
 We know:
 i = 0 represent 00
 i = 1 represent 01
 i = 2 represent 10
 i = 3 represent 11
So: Step 1: Loop from 0 to Size of Power Set


Now to know if the ith bit is set in a binary. We perform AND operation with a number which has set bit only at that ith index.
Eg: if number is 00001100 , and we have to check if 3nd bit is checked or not, we have to  perform  AND with a number(called j) whose only 3rd bit is set.
So we need to think of a number(j) which has only 1 set bit in its binary representation. AND if we got this number, we can left shift that number to bring the "1" bit at our desired place.

So only "1"(One) is the number which has only 1 bit on.

So to check if for number 00001100 if its 3rd bit is set. We perform AND by 1<<2(shift left the "1" bit by 2 places )

MOre examples: 
Eg: i = 2 or 10(in binary)
To check if 1st bit is set we perform 2 & 1 ==> 10 & 01 = 00. So if result is 0 it means not set.
To check if 2nd bit is set.We perform 2 & 2 ==> 10 & 10 == 1. So if result = 1, it means yes set.

SO STEP 2:
Perform i AND with j (j should be shifted left from 0 to N so that it can check all places which are set)

*/

void printPowerOrSubsequence(string s){
    int n = s.length();
    int power_size = pow(2,n);

    for(int i = 0; i< power_size ; i++){ // We need to generate all power 
    string temp ="";
        for(int j = 0; j< n ; j++){ // Loop from j = 0 to n because we have to shift 1 from 0 to n to check which all bits are set.
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