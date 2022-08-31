#include<bits/stdc++.h>
using namespace std;
/*
PROBLEM STATEMENT:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[ [1,1,6], [1,2,5], [1,7], [2,6] ]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[ [1,2,2], [5] ]
 
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

Edge case;
1) [1],  target = 0.
Ouptput: []

-----------------------------------------------------------------
IDEA /APPROACH:
*/

void printDS(vector<int> ds){
    if(ds.empty()){
        cout<<"[]"<<endl;
        return;
    }
    cout<<"{ ";
    for(auto it: ds)
        cout<<it<<" ";
    cout<<" } "<<endl;
}
void findUniqueCombinations(int index, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &combinations){
    
    cout<<"Called with F( "<<index<<" ) "<<endl;
    cout<<"DS is ";
    printDS(ds);
    // Note: here base case starts with target == 0 as it may be possible that we dont reach cur_ind = n-1 as in the mid way only we might found a subsequence with sums upto target.
    if(target == 0){
        cout<<"Target achieved and DS is :";
        printDS(ds);
        combinations.push_back(ds);
        return;
    }

    //if(arr[index] > target) - We cant include it here as the TC [1] and target = 0 would produce error on cur_index as after 1 call, it would call ind = 1 which doesnt not exits.
    // Hint dry run for the above edge case.
    //        return;
    
    cout<<"Entering loop for function F ( "<< index<<" ) "<<endl;

    for(int cur_index = index; cur_index < arr.size(); cur_index++){
        cout<<"Inside Loop with cur_ind = "<<cur_index<<endl;
        if(cur_index > index && arr[cur_index] == arr[cur_index - 1]){ // Check to avoid picking up same elements twice
            cout<<"Skipping arr["<<cur_index<<"] as its equal to arr["<<cur_index-1<<"]";
            continue;
        }

        if(arr[cur_index] > target){
            cout<<"arr[cur_ind]  = "<<arr[cur_index]<<" which is greater than remaining target = "<<target<<endl;
            cout<<" ----------- BREAKING LOOP at ind = "<< cur_index<< " --------------------- "<<endl;
            break; // No need to check for further targets
        }
            

        ds.push_back(arr[cur_index]);
        
        // moving to next index
        cout<<"F ( "<<cur_index<<" ) Now calling F ( "<<cur_index + 1<<" ) "<<endl;
        findUniqueCombinations(cur_index + 1, arr, target - arr[cur_index], ds, combinations); // We move to next index as we can include the current ans only once.
        
        cout<<"Poping "<<ds.back()<<endl;
        ds.pop_back();
    }
}
int main(){
    // vector<int> arr = {10,1,2,7,6,1,5}; // this will also produce same results. We need not to sort the array
    vector<int> arr = {1,1,1,1,2,2,2};
    //vector<int> arr = {1};
    int target = 4;
    vector<int> ds;
    vector<vector<int>> combinations;

    sort(arr.begin(), arr.end());
    findUniqueCombinations(0, arr, target, ds, combinations);

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