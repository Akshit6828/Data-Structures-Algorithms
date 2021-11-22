#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)

class Solution {
public:
    int maximum69Number (int num) {
    // Brute force: Traverse whole number and find the first 6
    string nums = to_string(num);
        for(int i =0;i<nums.length();i++){
            if(nums[i]== '6'){
                nums[i] = '9';
                break;
            }
        }
        return stoi(nums);
    }
};


int main(){
    boost;
    Solution obj;

    int t;
    cin>>t;
    while(t--){
        cout<<obj.maximum69Number(69)<<endl;
        cout<<obj.maximum69Number(66969)<<endl;
        cout<<obj.maximum69Number(9999)<<endl;
        cout<<obj.maximum69Number(66)<<endl;
        cout<<obj.maximum69Number(6669999)<<endl;
    }
    return 0;
}