#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


/*

* Frog jumping problem:
- Frog wants to go from 1 to Nth Step. It can only jump from 1 or 2 steps.
- Energy from jump from (i to j), it costs (arr[j] - arr[i]).
- Find the minimum energy used by Frog to reach from 1st stair to Nth stair. 
*/

int recursive_FrogJump(int ind, vector<int> &arr){ // TC: O(2^N), SC: O(2^N)
    if(ind == 0) // Energy required to jump from 0th stair to another is 0.
        return 0;
    
    int one_jump = recursive_FrogJump(ind - 1, arr) + abs(arr[ind - 1] - arr[ind]);
    int two_jump = INT_MAX;
    if(ind > 1) // As we cant jump back, 2 stairs from inds. 
        two_jump = recursive_FrogJump(ind - 2, arr) + abs(arr[ind - 2] - arr[ind]);
    
    return min(one_jump, two_jump);
}


int memoize_FrogJump(int ind, vector<int> &arr, vector<int> &dp){ // TC: O(N), SC: O(N + N){Stack space + dp array}
    if(ind == 0)
        return 0;
    
    if(dp[ind] != -1)
        return dp[ind];
    
    int left = memoize_FrogJump(ind - 1, arr, dp) + abs( arr[ind] - arr[ind - 1]);
    int right = INT_MAX;
    if(ind > 1)
        right = memoize_FrogJump(ind - 2, arr, dp) + abs( arr[ind] - arr[ind - 2]);

    return dp[ind] = min(left,right);
}


int tabulize_FrogJump(int n, vector<int> &arr){

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 0;
    
    for(int i = 1; i<=n; i++){
        int left = dp[i-1] + abs(arr[i-1] - arr[i]);
        int right = INT_MAX;
        if(i > 1)
            right = dp[i-2] + abs(arr[i-2] - arr[i]);
        
        dp[i] = min(left, right);
    }
    return dp[n];
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    vector<int> dp(n+1, -1);

    //cout<<recursive_FrogJump(n-1,arr)<<endl;
    //cout<<memoize_FrogJump(n-1,arr, dp)<<endl;
    cout<<tabulize_FrogJump(n-1,arr)<<endl;
}

int main(){
    boost;
    int t;
    cin>>t;
    int c = 1;
    while(t--){
        cout<<"Case #"<<++c<<": ";
        solve();
    }
    return 0;
}

/*
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 

Output:
7
2

*/
