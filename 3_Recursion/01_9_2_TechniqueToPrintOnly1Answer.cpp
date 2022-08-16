#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Question: Print any 1 subsequence whose sum = k.

Possible tricks: 
1) Use boolean parameter `found` and check if `found == true` dont print.
NOT RECOMMENDED because it doesnt not reduce our recusion calls. We still have to generate other recursive calls to which will get wasted even if we found the answer at the beginning.

2) Use functional approach:
RECOMMENDED as it reduces total recursion calls.

Idea: if f1() call executes first and if it returns true, no need to call f2() recursion call.

Boilerplate code important points:
1) Return type = bool
2) Base case:   a) return true  (if conditon satisfied)
                b) return false (if condition NOT Satisfied)

3) if(f1() == true) return true
4) if(f2() == true) return true
5) return false (if none of f1() or f2() returns true)

*/


// return type = bool
bool printSubsequenceWithKSum(int ind, vector<int> &arr , int sum, vector<int> &ds, int n, int K){
    if(ind == n){ // Note: This condition is important first, as we need a stopping conditon for the program as if index == n-1, then we cant make any furter subsequence.
        
        // Condition satisfied
        if(sum == K){
            for(auto it: ds) 
                cout<<it<<" ";
            cout<<endl;
            return true; // return true
        }
        
        // Condition not satisfied
        return false;
    }

    // Take
    ds.push_back(arr[ind]);
    sum+=arr[ind];

    // Checking if f1() returned true
    if(printSubsequenceWithKSum(ind +1, arr,sum,ds,n,K) == true){
        return true;
    }

    // Remove or back-track
    ds.pop_back();
    sum-=arr[ind];

    // Not Take
    // Checking if f2() returned true
    if(printSubsequenceWithKSum(ind +1, arr,sum,ds,n,K) == true)
        return true;

    // Returning false if none of the calls returned true
    return false;
}
int main(){
    int n, sum;
    cin>>n>>sum;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    vector<int> ds;
    cout<<"Subsequence with Sum = "<<sum<<" are:\n";

    if(printSubsequenceWithKSum(0, arr,0,ds,n, sum) == false)
        cout<<"No subsequence can be made "<<endl;
    return 0;
}