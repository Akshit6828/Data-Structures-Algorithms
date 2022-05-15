#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // 1 2 0 3 5 0 2
        int last_unique_element_known_index = -1;
        for(int i = 0;i< nums.size(); i++){
            if(nums[i] != 0){
                last_unique_element_known_index++;
                swap(nums[last_unique_element_known_index], nums[i]);
            }
        }
    }
};       



int main(){
    int t;
    cin >> t;
    while (t--){
    Solution obj;
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin>>x[i];
    obj.moveZeroes(x);
    /*for (int i = 0; i < res.size(); i++){
    for(int j = 0; j<res[i].size(); j++)
    cout<<res[i][j]<<" ";
    cout<<endl;
    }*/
    /*for (int i = 0; i < res2.size(); i++)
    cout<<res2[i]<<" ";*/
    }
    return 0;
    }