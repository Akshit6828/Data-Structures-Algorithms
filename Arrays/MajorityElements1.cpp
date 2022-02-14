#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int majorityElement(std::vector<int>& nums) {
        int ind = 0;
        int count = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[ind] == nums[i] )
                count ++;
            
            else
                count--;

            if(count == 0){
                ind = i;
                count = 1;
            }
        }
        return nums[ind];
    }
};