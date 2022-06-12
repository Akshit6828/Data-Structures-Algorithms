/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 
Example 1:

Input: nums = [4,2,4,5,6] 
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

LC Link: https://leetcode.com/problems/maximum-erasure-value/

*/

/*
HINTS:
1) The main point here is for the subarray to contain unique elements for each index. 
Only the first subarrays starting from that index have unique elements

2) This can be solved using the two pointers technique

Discuss: https://leetcode.com/problems/maximum-erasure-value/discuss/2140577/An-Interesting-Optimisation-or-JAVA-Explanation

*/

class Solution {
public:
    
    /*
    Edge cases: 4 4 4 2 4 6 , 5 2 2 5 
    */
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        
        int n = nums.size();
        int left = 0, right = 0,maxSum  = 0, curSum = 0;
        
        while(left < n && right < n){
            
            int curElement = nums[right];
            
            while(st.find(curElement) != st.end()){// Run while current element is already not deleted from the set.
                int leftElementOfWindow = nums[left];
                st.erase(leftElementOfWindow); // Trying to make window unique.
                curSum -= leftElementOfWindow;
                left++; // Moving the left increment so that it will now point to new left of window which will for sure have the unique starting element.
            }
            
            st.insert(curElement);
            curSum+=curElement;
            maxSum = max(maxSum, curSum);
            right++; // Iterating over next element
        }
        return maxSum;
    }
};