/*
Observations and intution:

If we know the max_subarray sum at i index. We can computer the max_subarray sum at ith index by either 2 choices ie.. a) to include the ith element (if it increases the subarray sum or its positive) or b) not to include the ith element in subarray sum (if it decreases the subarray sum or its negative).
Thus, max subarray sum can be 0.(Not necessary but here in the question.
So, consider taking the first element as the subarray sum.
maxSubArray(i) = max(maxSubArray(i-1) + i, maxSubArray(i));
Thus, maxSumTillCurrentIndex = max( maxSumTillCurrentIndex + currentIndex, maxSumTillCurrentIndex);
Store the MAXEST of all maxSumTillCurrentIndex by doing result = max(result, maxSumTillCurrentIndex).
return result;

Code:

    int maxSumTillCurrentIndex = arr[0];
    int res = maxSumTillCurrentIndex;
    for (int i = 1; i < arr.size(); i++)
    {
        maxSumTillCurrentIndex = max(maxSumTillCurrentIndex + arr[i], arr[i]);
        res = max(res, maxSumTillCurrentIndex);
    }
    return res;
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr) { //TC: O(N) , SC: O(1)
        int maxEnding = arr[0];
        int res = maxEnding;
        
        for(int i = 1; i<arr.size(); i++){
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;


    }
};

int main(){
    vector<int> vt = {-1,-1,3,-4,5,-1,3};
    Solution obj;
    int ans = obj.maxSubArray(vt);
    cout<<ans<<endl;
}