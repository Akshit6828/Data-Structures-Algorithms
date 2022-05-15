#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// TC: O(2^n) SC: O(2^n)
// Might be optimised by Backtracking, DP
// DP: O(N*sum)
int subsetSum(vector<int> &x, int n,  int sum){
    if(n == 0)
    return sum == 0 ? 1:0;
    else
    return subsetSum(x, n-1, sum) + subsetSum(x,n-1, sum - x[n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    int desired_sum;
    cin>>desired_sum;
    for(int i = 0; i< n; i++){
        cin>>x[i];
    }
    (subsetSum(x,n,desired_sum ) == 1 )?cout<<"Found":cout<<"Not Found";
    return 0;
}