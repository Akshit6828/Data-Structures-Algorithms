/*

PROBLEM:
We need to find the length of the longest wiggle subsequence. 
A wiggle subsequence consists of a subsequence with numbers which appears in alternating ascending / descending order.

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

SOLUTIONS:
Greedy (Best): TC: O(n), SC: O(1)

his problem is equivalent to finding the number of alternating max. and min. peaks in the array. 
Since, if we choose any other intermediate number to be a part of the current wiggle subsequence, the maximum length of that wiggle subsequence will always be less than or equal to the one obtained by choosing only the consecutive max. and min. elements.

- It is equall to make an alternating sub-sequence or to count no of points where sequence becomes alternating.
- If single element is present in array than ans = 1.
- If more than 1 element is present that the minumum ans = 2. (As we can consider any 2 elements and they make the difference)
- Eg: 1 2 3 4 -> we can consider any (1,2) or (2,4) or (1,4) .. and dif = 1. Thus, it makes a sequence of length = 2 atleast.

Edge Case: 
[3,3,3,2,5] here prevdiff and currdiff becomes 0.

*/

// Code:
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // It is equall to make an alternating sub-sequence or to count no of points where sequence becomes alternating.
        // If single element is present in array than ans = 1.
        // If more than 1 element is present that the minumum ans = 2. (As we can consider any 2 elements and they make the difference)
        //  Eg: 1 2 3 4 -> we can consider any (1,2) or (2,4) or (1,4) .. and dif = 1. Thus, it makes a sequence of length = 2 atleast. 
        
        // Edge case: [3,3,3,2,5]
        int sz = nums.size();
        if(nums.size() < 2)
            return sz;
        int prevDifference = nums[1] - nums[0];
        int count = prevDifference != 0 ? 2 : 1; // Initially if both 2 elements have same count, then we wont consider as 0 difference isnt considered. Thus, in this case the count of elements in sequence will only be 1(which would be 2nd element or array ie. discarding the first element)
        
        for( int i = 2 ;i < sz ; i++){
            
            int currDifference = nums[i] - nums[i-1];
            
            if( (prevDifference <= 0 && currDifference > 0 )  || (prevDifference >= 0 && currDifference < 0 ) ) {
                count++;
                prevDifference = currDifference;
            }
            
        }
        
    return count;
    }
};