/*
LC Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Solution 1: Use 2 pointers to find any pair.
Possible Solution 2: Use binary search to find the maxest index which is greater than target and then apply two pointers.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high){ // O(N) solution
            
            int cur_sum = nums[low] + nums[high];
            if( cur_sum == target){
                indexes.push_back(low+1);
                indexes.push_back(high+1);
                break;
            }
            else if(cur_sum > target)
                high--;
            else
                low++;
        }
        
        return indexes;
    }
};