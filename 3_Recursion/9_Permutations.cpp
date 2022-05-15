#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int funcall = 0;
class Solution {
 
public:
    
    void generatePermutation(vector<int> &nums, int index, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i< nums.size() ; i++){
            swap(nums[i], nums[index]);
            //cout<<"swap occured between x[ "<<i <<" ] and x [ "<< index<<" ] "<<endl;
            //cout<<"String now is "<<
            generatePermutation(nums,index + 1, ans);
            swap(nums[index] , nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        generatePermutation(nums, 0, ans);
        return ans;
    }
};


void Per(string s, int index = 0){
    funcall++;
    cout<<"\n--------------------------------------- \n";
    cout<<"Function Call number "<<" -> "<<funcall<<endl;
    if(index == s.length() - 1){

            cout<<"Falling into base case where index has reached (n - 1) and string is "<< s<<endl;

            cout<<"Returning to above called function \n";
            cout<<"\n*********************************************** \n";
            return;
        }
        
        for(int i = index; i< s.length() ; i++){
            swap(s[i], s[index]);
            cout<<"swap occured between s[ "<<index <<" ] and s [ "<< i<<" ] "<<endl;
            cout<<"String now is "<<s<<endl;
            Per(s,i+1);
            swap(s[index] , s[i]);
            funcall--;
        }
        
}
int main(){
    Solution obj;
    vector<int> x ={1,2,3};

    string s = "ABC";
    Per(s,0);

    /*vector<vector<int>> ans = obj.permute(x);
    int count = 1;
    for(auto i: ans){
         cout<<count<<":   ";
        for(auto j: i){
             cout<<" "<<j<<" ";
        }
        count++;
        
        cout<<endl;
    }
    */
    return 0;
}