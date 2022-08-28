#include<bits/stdc++.h>
#include<iostream>
using namespace std;


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