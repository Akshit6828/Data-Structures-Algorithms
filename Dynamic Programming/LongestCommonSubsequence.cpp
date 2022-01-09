#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>



void solve(){
    string s1,s2;
    cin>>s1>>s2;

    int m = s1.length();
    int n = s2.length();
   
    int dp[m+1][n+1];
    for(int i =0; i<=m;i++){
        dp[i][0] = 0;
    }
    for(int i =0; i<=n;i++){
    dp[0][i] = 0;
    }

    int ans = 0;
    for(int i = 1;i <=m;i++){
        for(int j =1; j<=n;j++){
            if(s1[i-1] == s2[j-1])
            dp[i][j]= 1+dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"Longest Common Subsequence ="<<dp[m][n]<<endl;


}

int main(){
    boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}