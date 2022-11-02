#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
- You are climbing a staircase. It takes n steps to reach the top.
- Each time you can either climb 1 or 2 steps.
- In how many distinct ways can you climb to the top?
*/


// TC: Similar to O(2^n) as for every N, we are calling 2 calls and for 2^N is calling. Actually its 2 ^ golden ratio

int recursive(int cur_step){ // TC: O(2^N), SC: O(2^n){Thinking of stack space}
    if(cur_step == 0 || cur_step == 1)
        return 1;
        
    int ones_Step_Counts = recursive(cur_step - 1);
    int two_Step_Counts = recursive(cur_step - 2);
    return ones_Step_Counts + two_Step_Counts;
}

// Top to Bottom Approach. (Not necessary but starts from N and goes to 0) Or Starts from opposite side of the base case and goes down.
int memoize_steps(int cur_step, vector<int> &dp){ //TC: O(N) , SC: O(2*n){Stack space and DP array}
        
        if(cur_step == 0 || cur_step == 1)
             return 1;
        
        if(dp[cur_step] != -1)
            return dp[cur_step];
        
        dp[cur_step] = memoize_steps(cur_step - 1,dp) + memoize_steps(cur_step - 2,dp);
        return dp[cur_step];
        
    }

// Bottom - Up Approach. (Not Necessary but we start from 0 and goes to N) or Start from base case and go till the Nth Number which is the opposite side of Base case.
int tabulate_steps(int total_steps){ // TC: O(N), SC: O(N)
        if(total_steps == 1 || total_steps == 0)
            return 1;
        
        vector<int> dp(total_steps+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=total_steps; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[total_steps];
}
    
/*
Optimization is based on the fact that we only 2 variables (prev1) and (prev2) which will be storing the f(n-1) and f(n-2) values.
Thus, we only need 2 variables.
prev1 = unique ways for 1 step behind 
prev2  = unique ways for 2 step behind
*/
int optmized_Tabulation(int total_steps){ // TC: O(N), SC: O(1)
        if(total_steps == 1 || total_steps == 0)
            return 1;
        
        vector<int> dp(total_steps+1);
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2; i <=total_steps; i++){
            int total_unique_steps_till_now = prev1 + prev2;
            prev2 = prev1;
            prev1 = total_unique_steps_till_now;
        }
        
        
        return prev1;
    }

void print1DVector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
}
int main(){
    
    int n = 4;
    cout<<recursive(n)<<endl;
    vector<int> dp( n+1, -1);
    cout<<memoize_steps(n, dp)<<endl;
    print1DVector(dp);
    cout<<endl;
    cout<<tabulate_steps(n)<<endl;
    cout<<optmized_Tabulation(n)<<endl;
    return 0;
}