#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isValidPartition(string s){
    cout<<"validity called for "<<s<<endl;
    int low = 0, high = s.size() - 1;
    while(low < high){
        if(s[low] != s[high]) return false;
        low++;
        high--;
    }
    return true;
}

void solve(int ind, string s, vector<vector<string>> &ds, vector<string> &ans, string cur_str){
    cout<<"function called for  ind = "<<ind <<endl;
    if(ind == s.length()){
        ds.push_back(ans);
        return;
    }

    for(int i = ind; i < s.length(); i++){
        cur_str+=s[ind];
        if(isValidPartition(cur_str)){
            cout<<"Pushed cur_str in ans"<<endl;
            ans.push_back(cur_str);
            solve(ind + 1, s, ds,ans, cur_str);
            cur_str.pop_back(); // Backtacking so that we can try other index to parition too.
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ds;
    int ind = 0;
    vector<string> ans;
    string cur_str = "";
    solve(ind, s, ds,ans, cur_str);
    return ds;
}
int main()
{
    string s;
    cin>>s;
    vector<vector<string>> partitions;
    partitions = partition(s);

    for(auto str:partitions){
        cout<<"[ ";
        for(auto st: str)
            cout<<st<<" ";
        printf("]\n"); 
    }
    return 0;
}