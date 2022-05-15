#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// This problem cna be solved efficiently using DP.

int maxPiece(int n , int a, int b, int c){ // TC: O(3^n)
    if(n  == 0)
        return 0;
    if(n < 0)
        return -1;

    int res = max( maxPiece(n-a,a,b,c), max ( maxPiece(n-b,a,b,c), maxPiece(n-c,a,b,c) ) );

    //    7 2 6
    if(res == -1)                                                                                                                                                                  
    return -1; // IMP: As if res = -1 it means none rope is able to cut
    // So in this case we return -1 as else -1 + 1 = 0 and 0 + 1 = 1 (parent call) can cause a probelm for this test case.
   return res+1;
   // 19 2 2 2

}
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<maxPiece(n,a,b,c);
    return 0;
}