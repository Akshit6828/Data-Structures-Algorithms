#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*
Important Points:
1) Let start and end be the index where the string is to be partioned.
2_substr(i,j) in c++ works as start from i and add j steps.

Understanding recursive steps:
1) Try partioning a substring from start - end.
2) Check if the partioned substring ( s.substr(start, end -start + 1) ) is a palindrome or not.
    2.1) If yes, include into the answer, try searching for next string where the new start = end + 1 (repeat step 1: Recursion called).
    2.2) Also try to backtrack as from one index(ie: start) there can be multiple indexes ie(end), which can generate a palindrome substring. So its important to backtrack and check for other string too.

Example explaining 2.2: 
string = aaa. lets say start = 0, end = 1. ie(substring = aa) makes a palindrome.
BUT: 
start = 0, end = 3 ie(substring aaa) ALSO MAKES a new palindrome. Thus, its important to backtrack the last inserted substring into the answer so in order to try new combinations.

Algo/Idea:
1) Start trying to check every substring from [start- end] till end == s.size() (ie. The end of string).
2) Loop from start to s.size() and check which substring is a paindrome partition.
3) If the substring is a palindrome, insert it into the ds and call the next recrusive function with now (start = end + 1), so that it can start partioning again with the next index with the help of recursive function..
4) Remove the last inserted string in order to try other partitions too.

*/

 bool isPalindrome(string s, int low , int high){
        while(low < high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    
    void solve(int start, string s, vector<vector<string>> &ans, vector<string> &ds){
        
        // Base case: As this denotes that we have reached end of string and no more partition can be done.
        if(start == s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int end = start; end < s.size(); end++){
            
            if(isPalindrome(s,start,end)){
                string str = s.substr(start, end - start + 1);
                ds.push_back(str);
                solve(end + 1, s, ans, ds); // Note: Here solve(end+1) and not "start + 1" as "end" will be the latest index where the new palindome string is found and inserted.
                ds.pop_back(); // Backtracking it, so that we can try the last palindrome inserted with other next indexes too.
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int start = 0;
        solve(start,s,ans,ds);
        return ans;
    }

int main()
{
    string s;
    cin>>s;
    vector<vector<string>> partitions;
    partitions = partition(s);

    for(auto str:partitions){
        cout<<"[";
        for(auto st: str)
            cout<<st<<" ";
        printf("]\n"); 
    }
    return 0;
}