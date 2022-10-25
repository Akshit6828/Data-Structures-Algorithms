#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Program to print nth fibonacci series.
Fibo series: 0  1  1  2  3  5  8 13  21  34
             0  1  2  3  4  5  6  7   8   9
*/

void print1DVector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
}

// TC: Similar to O(2^n) as for every N, we are calling 2 calls. and for 2^N is calling. Actually its 2^ golden ratio
int recursive_fibo(int n){ // TC: O(2^n)
    if(n <=1)
        return n;
    
    return recursive_fibo(n-1) + recursive_fibo(n-2);
}

// Top to Bottom Approach. (Not necessary but starts from N and goes to 0) Or Starts from opposite side of the base case and goes down.
int memoization_fibo(int n , vector<int> &dp){ // TC: O(n) Sc:O(2*N) --> O(n){dp array} + O(n){stack space}

    if(n <= 1)
        return n;
    
    if(dp[n] != -1) 
        return dp[n];

    dp[n] = memoization_fibo(n-1,dp) + memoization_fibo(n-2, dp);
    return dp[n];
}

// Bottom - Up Approach. (Not Necessary but we start from 0 and goes to N) or Start from base case and go till the Nth Number which is the opposite side of Base case.
int tabulation_fibo(int n, vector<int> &dp){ // TC: O(N) SC:O(N)
    
    if(n <= 1)
        return n;
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/*
Optimization is based on the fact that we only 2 variables (prev1) and (prev2) which will be storing the f(n-1) and f(n-2) values.
Thus, we only need 2 variables.
prev1 = 1 step behind
prev2  = 2 step behing
*/
int optimized_tabulation_fibo(int n){ // TC: O(n), SC: O(1)
    if(n <= 1)
        return n;
    
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i <=n ; i++){
        int current_fibo = prev1 + prev2;
        prev2 = prev1;
        prev1 = current_fibo;
    }
    return prev1;
}


int main(){
    
    int n = 1;
    cout<<recursive_fibo(n)<<endl;

    vector<int> dp( n+1, -1);
    cout<<memoization_fibo(n,dp)<<endl;
    print1DVector(dp);
    cout<<endl;
    cout<<tabulation_fibo(n,dp)<<endl;
    cout<<optimized_tabulation_fibo(n);
    return 0;
}