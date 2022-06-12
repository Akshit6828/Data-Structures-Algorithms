/*
LC Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

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