#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Question: Print count subsequence whose sum = k.

Possible tricks: 
1) Use integer parameter `count` and update `count`
2) Use functional approach:

Idea: if f1() call executes first and if it returns the desired answer, return(add) 1 to answer and if it doesnt returns the desired answer, return(add) 0.


Boilerplate code important points:
1) Return type = int
2) Base case:   a) return 1  (if conditon satisfied)
                b) return 0 (if condition NOT Satisfied)

3) int left = f1()
4) int right = f2()
5) return left + right

Note: if there are N recursion calls, use loops and store answer in a result variable and return ans.

Eg:
----------------------------------
int result = 0;
for(int i = 1 ; i<=N; i++){
    result+=f(i);
}
return result;
----------------------------------
*/


// return type = int
int CountSubsequenceWithKSum(int ind, vector<int> &arr, int sum, int n, int K){ // TC:O(2^n) as we have 2 options(take/not take) for each of n indexes.
    
    /* 
    If array contains ONLY POSITIVE, we can slighlty optimize it by adding this base case
    if(sum > K) 
        return 0;
    knowing my answer will only exceed if I do take/not take from current index(ind)
    */
    
    if(ind == n){ // Note: This condition is important first, as we need a stopping conditon for the program as if index == n-1, then we cant make any furter subsequence.
    
        // Condition satisfied
        if(sum == K){
            return 1; // return 1
        }
        // Condition not satisfied
        return 0;
    }

    // Take
    sum+=arr[ind];

    // Storing f1() in left
    int left = CountSubsequenceWithKSum(ind +1, arr,sum,n,K);
        

    // Remove or back-track
    sum-=arr[ind];

    // Not Take
    // storing f2() in right
    int right = CountSubsequenceWithKSum(ind +1, arr,sum,n,K);

    // Returning left + right
    return left + right;
}
int main(){
    int n, sum;
    cin>>n>>sum;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    // Here we need not any ds to store the subsequence. We just need count. So vector<int> ds can be ignored as we are only concerned with sum.
    cout<<"Count of Subsequence with Sum = "<<sum<<" are: ";

    cout<<CountSubsequenceWithKSum(0, arr,0,n, sum);
    return 0;
}