#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    // Compiler are free to total no of bits. Its not standarized by the language.
    int x = 3; // 000 .... 011
    int y = 6; // 000 .... 110
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    
    int a = x & y; // 000 .... 010 = and ( 1&1 = 1), (0&1 = 0), (1&0 = 0), (0&0 = 0)
    int b = x | y; // 000 .... 111 = or  ( 1|1 = 1), (0|1 = 1), (1|0 = 1), (0|0 = 0) :
    int c = x ^ y; // 000 .... 011 = xor ( 1^1 = 0), (0^1 = 1), (1^0 = 1), (0^0 = 0) : Both different then 1.
    
    
    cout<<"x&y : "<<a<<endl;
    cout<<"x|y : "<<b<<endl;
    cout<<"x^y : "<<c<<endl;

    // Shift operators :
    int num1 = 3, num2 = 5;
    
    cout<<"num1 = "<<num1<<endl;
    cout<<"num2 = "<<num2<<endl;

    int d = num1 << 3; // d = num * 2^3 = num * 8 -> 3*8 = 24
    int e = num2 >> 2; // e = num / 2^2 = num / 4 -> 5/4 = 1
    
    
    cout<<"num1 << 3 : "<<d<<" ( num1 * 2^3 => num * 8 )"<<endl;
    cout<<"num2 >> 2 : "<<e<<"  ( num2 / 2^2 => num / 4 )"<<endl;
    
    int num3 = -12; // signed int is represented by 2's complement.
    // binary representation of -12 is : 1111 1110
    // By default, int is signed.
    // -12 = 1111 1100
    // ~(-12) = 0000 0001
    // ~(-12) = 1111 1110
    cout<<"num3 = "<<num3<<endl;
    int f = (~num3);
    cout<<"~ num3 : "<<f<<endl;

    int num4 = 12; // signed int is represented by 2's complement.
    // binary representation of 12 is : 0000 1100
    // 12 = 0000 1100
    // ~(12) = 1111 0011
    cout<<"num4 = "<<num4<<endl;
    int g = (~num4);
    cout<<"~ num4 : "<<g<<endl;

    return 0;
}