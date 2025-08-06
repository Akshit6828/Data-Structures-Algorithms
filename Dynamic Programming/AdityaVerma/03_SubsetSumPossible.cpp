#include <bits/stdc++.h>
using namespace std;

 /*
    -----> SUM  ---> x axis
    *   [][][][][][]
    n   [][][][][][]
    *   [][][][][][]
    
        00 01 02 03..
        10 11 12 13
        20 21 22 23
        30 21 32 33
    */
    
// Debugging purpose only
    void printDp(vector<vector<bool>> &dp) {
	cout<<"print dp"<<endl;
	for(auto x: dp) {
		cout<<"[";
		for(auto y: x)
			cout<<y<<" , ";
		cout<<"]"<<endl;
	}
}

bool subsetSumPossible(vector<int> &arr, int sum, int n, vector<vector<bool>> &dp){
    cout<<"called"<<endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=sum; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    for(int i = 1; i <= n;i++){
        for(int j = 1; j<=sum; j++){
            
            // item  <= j(here j means sum as j represents sum as sum is plotted on y axis(column axis))
            if(arr[i-1] <= j){ // We can include the item in our set
                // Take item. so col index will be [j - arr[i-1]]        || not take
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }else{ // we cant include this in our set
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
}

int main()
{
    int n;
    cin>>n;
    cout<<"Enter elements"<<endl;
    vector<int> arr(n);
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    
    cout<<"Enter desired subset sum"<<endl;
    int sum;
    cin>>sum;
    
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));

    bool ans = subsetSumPossible(arr, sum, n, dp);
    cout<<"Possible = "<<ans<<endl;
    return 0;
}