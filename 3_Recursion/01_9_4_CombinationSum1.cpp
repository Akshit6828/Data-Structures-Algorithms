#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*

Problem:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

-----------------------------------------------------------------------------------
Questions before coding up:
1) Can all be negatives too?
2) Can target given be negative also if the array contains -ve numbers.

Explanation:
Every possible combination is made either by multiple/single take(T) or Not-Take(X)
Eg: Array [2,3,6,7,] and target = 7. The combination [2,2,3] is made by following decision.
[ TT, T, X, X].

Note: We only decided the following combination after exploring all indexes(i == n) and then deciding if this combination sum = target or not.

1) For every index, we have 2 options take or not take.
2) So for every index, we can have 2 recursive functions, 1. to handel take and 2. to handel not take.
3) For take, stay on same index, deduct the value at current index from the target.
4) For not take, increment the current index and DONOT deduct the target.

Base case deciding
1) Check if ind == n and NOT ind == n-1 as we need to reach that point where no index exist. So, as n index doest not exist in array of size(n), so base case would be ind == n.
2) if(sum == 0) then only it means, that we have achieved the target. So its another important base case to check.

TC: O( (2^k) * n)
1) Where k times at worst the minimum value of all combinations is used. 2^k as we are exploring take / not -take for that decision.
2) n for pushing the current subsequence (ds) into the final answer. Remember pushing 1 vector into another is not a O(1) operation.
*/

void findCombinations(int cur_index, vector<int> &arr, int target_sum, vector<int> &ds,vector<vector<int>> &combinations){
    
    /*
        We can also add another base case if we have all elements of array as positive only.
        if(arr[ind] > sum)
            return;
    */

    if(cur_index == arr.size()){// It means we have reached the next to the last element and it must be handeled here.
        if(target_sum == 0)
            combinations.push_back(ds);
        return;
    }

    if(arr[cur_index] <= target_sum){// It means we can include any occurence of this arr[ind] in our ans
        target_sum-=arr[cur_index];
        ds.push_back(arr[cur_index]);
        findCombinations(cur_index, arr, target_sum, ds, combinations); //Taking Condition: Explore more on to same index (Taking the current index and remaning it here only)
        target_sum+=arr[cur_index];
        ds.pop_back();// Backtracking it and removing it again so it may try the right side branch 
    }
    //else: DONOT INCLUDE ELSE as then only the first subsequence will be printed as if-else are opposite and for each index, (NOT TAKE or TAKE will happen, rather than both TAKE and NOT-TAKE)
    // Thus its important to NOT TO INCLUDE here if-else condition,
    findCombinations(cur_index+1, arr,target_sum,ds,combinations); // We cant include and thus, we should try next steps.
    
}
int main(){
    //vector<int> arr = {5,6,1,2,3,4}; this will also produce same results. We need not to sort the array
    vector<int> arr = {1,2,3,4,5,6};
    int target = 6;
    vector<int> ds;
    vector<vector<int>> combinations;
    findCombinations(0, arr, target, ds, combinations);

    for(auto i: combinations){
        int sum = 0;
        cout<<"[ ";
        for(auto j : i){
            cout<<j<<" ";
            sum+=j;
        }
        cout<<"] = "<<sum<<endl;
    }
    return 0;
}