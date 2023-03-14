#include<bits/stdc++.h>
#include<iostream>

#define deb(x) cout<<#x<<" = "<<x<<endl;
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
    // There are generally 6 bitwise operators in C++. AND(&), OR(|), XOR(^), LEFT SHIFT(<<), RIGHT SHIFT(>>),BITWISE NOT(~) 
    // Compiler are free to total no of bits. Its not standardized by the language.
    
    int x = 3; // 000 .... 011
    int y = 6; // 000 .... 110
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    
    // ************************* AND | OR | XOR OPERATOR ****************
    int a = x & y; // 000 .... 010 = and ( 1&1 = 1), (0&1 = 0), (1&0 = 0), (0&0 = 0)
    int b = x | y; // 000 .... 111 = or  ( 1|1 = 1), (0|1 = 1), (1|0 = 1), (0|0 = 0) :
    int c = x ^ y; // 000 .... 011 = xor ( 1^1 = 0), (0^1 = 1), (1^0 = 1), (0^0 = 0) : Both different then 1.
    
    
    cout<<"x&y : "<<a<<endl;
    cout<<"x|y : "<<b<<endl;
    cout<<"x^y : "<<c<<endl;

    // ************************* LEFT SHIFT | RIGHT SHIFT OPERATOR ****************
    int num1 = 3, num2 = 5;
    
    cout<<"num1 = "<<num1<<endl;
    cout<<"num2 = "<<num2<<endl;

    int d = num1 << 3; // d = num * 2^3 = num * 8 -> 3*8 = 24
    int e = num2 >> 2; // e = num / 2^2 = num / 4 -> 5/4 = 1
    
    
    cout<<"num1 << 3 : "<<d<<" ( num1 * 2^3 => num * 8 )"<<endl;
    cout<<"num2 >> 2 : "<<e<<"  ( num2 / 2^2 => num / 4 )"<<endl;
    cout<<"0 <<1 : "<<(0<<1)<<"  ( 0 * 2^1 => 0  )"<<endl;
    
    // *********************** BITWISE NOT(~) OPERATOR ****************************
    // It works differently for SIGNED(Negatives) and UNSIGNED(Positives) NUMBERS.
    
    unsigned int num4 = 12; // Unsigned int. Since its unsigned, it wont be negative.
    // Unsigned numbers are in range [0 to 2^31 -1 ].
    
    // Binary representation of 12 is : 0000 1100
    // 12 = 0000 1100
    // ~(12) = 1111 0011
    cout<<"num4 = "<<num4<<endl;
    int g = (~num4);
    cout<<"~ num4 : "<<g<<endl;
    cout<<"Binary representation of ~num4 = "<<endl;
    display_binary(g);


    int num3 = -12; // signed int is represented by 2's complement.
    // binary representation of -12 is : 1111 1110
    // By default, int is signed.
    // -12 = 1111 1100
    // ~(-12) = 0000 0001
    // ~(-12) = 1111 1110
    cout<<"num3 = "<<num3<<endl;
    int f = (~num3);
    cout<<"~ num3 : "<<f<<endl;

    

    return 0;
}