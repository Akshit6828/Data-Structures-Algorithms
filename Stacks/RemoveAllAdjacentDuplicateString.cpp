#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        // Building a stack of unique adjacent duplicates
        for(char c:s){
            
            if(st.empty() || st.top().first != c){
                st.push({c,1});
                //cout<<"Pushed "<<c<<"with freq 1"<<endl;
            }
            
            else{
                
                int prevCount = st.top().second;
                //cout<<"st.top().second has prevCount ="<<prevCount<<endl;
                st.pop();
                st.push({c, prevCount + 1});
                //cout<<"New Top.second() became "<<st.top().second;
            }
            
            if(st.top().second == k){
                st.pop();
                //cout<<"Popped top\n";
            }
                
        }
        
        string ans;
        
        while(!st.empty()){
            
            char c = st.top().first;
            int len = st.top().second;
            for(int i = 1; i <=len ; i++)
                ans.push_back(c);
            
            st.pop();
        }
            
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};