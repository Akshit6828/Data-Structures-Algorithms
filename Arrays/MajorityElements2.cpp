#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(std::vector<int>& nums) {

        std::vector<int> majorElements;
        int val1 = -1, val2 = -1, count1 = 0, count2 = 0;
        
        for(int &i :nums){
            if(i == val1) count1++;
            else if(i == val2) count2++;
            else if(count1 == 0) {
                val1 = i;
                count1 = 1;
            }
            else if(count2 == 0) {
                val2 = i;
                count2 =1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
      count1 = 0, count2 = 0;
        
        for(int i: nums){
        if(i == val1)
            count1++;
        if(i == val2)
            count2++;
        }
        
        if(count1 > nums.size() / 3 )
            majorElements.push_back(val1);
        if(count2> nums.size() / 3 && val1!=val2)
            majorElements.push_back(val2);
    return majorElements;
    }
    
    
};