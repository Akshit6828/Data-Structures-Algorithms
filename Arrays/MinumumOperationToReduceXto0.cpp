/*
Problem:
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

LC Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

/*
Observations:
Always choosing the largest end wont be an optimal choice.
Example Input:
[2,3,1,6,4]
5

* If we proceed with choosing the optimal choice (largest end) we might lead to -1 in above case.
Above approach might do this:
1. Choose 4: x = 5-4 = 1.
2. It finds that now sum = 1 isnt possible so it return -1.(which is wrong).

KEY NOTES:

1) We could use dfs+memo or BFS(recursive), but they are too slow and will TLE (?)
2) If it exists an answer, then it means we have a subarray in the middle of original array whose sum is == totalSum - x.
3) If we want to minimize our operations, then we should maximize the length of the middle subarray.
4) Then the question becomes: 
    Find the Longest Subarray with Sum Equals to "TotalSum - X"
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for(auto num : nums)
            sum += num;
        
        int target = sum - x;
        int curSum = 0, maxLen = 0;
        
        if (target == 0)  // It means that x = sum . ie. whole array is required to form x as sum.
            return n;
        
        bool found = false;
        int left = 0;
        for(int right = 0; right < n ; right++){
           curSum+=nums[right];
            
            while(left <= right && curSum > target){ // left <=right because it might be possible that left == right == value which is greater than desired target.
                curSum-=nums[left];
                left+=1;
            }

            if(curSum == target){
                found = true;
                maxLen = max(maxLen, right - left + 1); // +1 for O- based indexing
            }
                        
        }
        
        return found == true? n - maxLen : -1;
    }
};