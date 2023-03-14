#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Helper function from my library
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

/* 
The idea is to iterate till the MSB(Most Significant Bit) and count each time if we find any bit as '1' by doing n&1.
*/
int NaiveSolution(int n){ // TC: O(d) where d = no of bits from 0 to MSB.  SC: O(1)
    int total_setbits = 0;
    while(n > 0){
        if(n&1 != 0)
            total_setbits++;
        n/=2; // n>>1 can also be used;
    }
    return total_setbits;
}

/*
Method 2: USING BRIAN KERNINGAM's ALGORITHM.
This method basically works in O(no. of setbits) in a number.
It says that when we perform (&) AND Operation of N with N-1, the last set bit gets unset and all the trailing 0's after that are converted into 1.

Why N & (N-1) would reset last bit?
Because if you want to form N-1 from N, just unset the last set bit and invert all the rest of bits.

So basically whenever we perform, N & N-1, we end up setting all the bits as 0 from the last set bit on RHS of the last set bit there would be combinations of (0&1) or (1&O) or (0&0) which all are equal to 0.
20 = 10100
19 = 10011
*/

int Optimize_Using_Brian_Kernighan_Algo(int n){ // TC: O(no of setbits) SC: O(1)
    int count = 0; 
    while(n>0){
        n = n&(n-1);
        count++;
    }
    return count;
}

int Optimize_Using_LookUpTable(int n){
    
}
int main(){
    int n = 31;
    cout<<NaiveSolution(n)<<endl;
    cout<<Optimize_Using_Brian_Kernighan_Algo(n);
    return 0;
}