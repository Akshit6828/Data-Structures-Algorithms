#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>



void solve(){
    int n, w;
    cin>>n>>w;

    int wt[n];
    int val[n];
    for(int i = 0;i<n;i++){
        cin>>val[i]>>wt[i];
    }         

    int dp[n+1][w+1];
    for(int i =0 ;i <=n;i++)
    dp[i][0] = 0;
    for(int i =0 ;i <=w;i++)
    dp[0][i] = 0;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=w;j++){

            if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }

            else
            dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
        }
    }
    cout<<"Max Val = "<<dp[n][w];
}

int main(){
    boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}