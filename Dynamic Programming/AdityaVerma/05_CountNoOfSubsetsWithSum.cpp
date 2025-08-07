// Given an array, give no of subsets with the given sum
// Note this will work only if subsets donot contains negative numbers.

// Note: arr[i] > 0 only!
// For array containing negative numbers, i have appended the solution or approach below


#include <bits/stdc++.h>
using namespace std;

 void printDp(vector<vector<int>> &dp) {
	cout<<"print dp"<<endl;
	for(auto x: dp) {
		cout<<"[";
		for(auto y: x)
			cout<<y<<" , ";
		cout<<"]"<<endl;
	}
}

/**
Note:
The method fails when the input array has any zeros. 
For eg: n=3, sum=0.
We can have a set here as {0,1,2}, so there'll be subsets of {} and {0} possible hence count will be 2. This is true for multiple other input arrays where actually count >1 for sum=0, but we initialized count=1 for all input arrays when sum=0. 

Here's a small fix:
We initialize the first column of the array acc to the formula: 2 ^ (no of zeros in the array at that size).

Hence, for eg: arr={0,0,1,0}, sum=0
For n=0, value will be 2^0 = 1, i.e {} 
For n=1, value will be 2^1 = 2, i.e. {} and {0}
For n=2, value will be 2^2= 4, i.e. {}, {0}, {0} and {0,0} 
For n=3, value will be 2^2 = 4, i.e. {}, {0], {0}, and {0,0}
For n=4, value will be 2^3 = 8 i.e. {}, .............., {0,0,0}

*/

int countNoOfSubsetsWithSum(int n, int sum, vector<int> arr, vector<vector<int>> &dp){
    
    // Initialization for subset sum
    for(int col = 0;col<=sum; col++){
        dp[0][col] = 0;
    }
    for(int row = 0; row<=n; row++){
        dp[row][0] = 1;
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            
            int num = arr[i - 1];
            if( num <= sum){
                
                dp[i][j] = dp[i-1][j - num] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
    
    
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int sum;
    cout<<"Enter desired sum"<<endl;
    cin>>sum;
    
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    cout<<countNoOfSubsetsWithSum(n,sum,arr,dp);
    return 0;
}


/*
: What if array contains negatives also?

❌ Problems:
- Array indexing for dp[i][j - num] fails if j - num < 0.
- The dp table is sized only for non-negative sums: dp[n+1][sum+1]. If sum is negative, this doesn't make sense.

- The range of possible subset sums (when using negatives) includes negative numbers, which your DP table doesn't handle.

✅ Solution Strategy:
- When the array has negatives, zeros, or both:
- Shift the sum range to non-negative values using an offset.
- Determine the minimum and maximum possible sums using all elements.
- Resize the dp table to handle negative to positive sums by shifting all indices.

Determine range:
// Step 1️⃣: 
int minSum = 0, maxSum = 0;
for(int num : arr){
    if(num < 0) minSum += num;
    else maxSum += num;
}

Step: 2️⃣: Use offset to shift negative indices:

int offset = -minSum;  // This ensures all indices are non-negative

Step 3️⃣: Initialize DP vector
vector<vector<int>> dp(n + 1, vector<int>(maxSum - minSum + 1, 0));
dp[0][offset] = 1;  // 1 way to make sum 0

Step 4️⃣: Fill DP:

for(int i = 1; i <= n; i++){
    for(int j = minSum; j <= maxSum; j++){
        int shifted_j = j + offset;
        int include = 0;
        if(j - arr[i - 1] >= minSum && j - arr[i - 1] <= maxSum){
            include = dp[i-1][j - arr[i - 1] + offset];
        }
        int exclude = dp[i-1][j + offset];
        dp[i][shifted_j] = include + exclude;
    }
}

FINAL CODE:
#include <bits/stdc++.h>
using namespace std;

int countNoOfSubsetsWithSum(int n, int sum, vector<int> arr){
    int minSum = 0, maxSum = 0;
    for(int num : arr){
        if(num < 0) minSum += num;
        else maxSum += num;
    }

    int offset = -minSum;
    int totalRange = maxSum - minSum + 1;
    vector<vector<int>> dp(n + 1, vector<int>(totalRange, 0));

    dp[0][offset] = 1; // 1 way to make sum = 0

    for(int i = 1; i <= n; i++){
        for(int j = minSum; j <= maxSum; j++){
            int shifted_j = j + offset;

            int include = 0;
            int prev_sum = j - arr[i - 1];
            if(prev_sum >= minSum && prev_sum <= maxSum)
                include = dp[i - 1][prev_sum + offset];

            int exclude = dp[i - 1][shifted_j];

            dp[i][shifted_j] = include + exclude;
        }
    }

    if(sum < minSum || sum > maxSum)
        return 0;
    return dp[n][sum + offset];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout << "Enter desired sum: ";
    cin >> sum;

    cout << "Count of subsets with sum " << sum << " is: " << countNoOfSubsetsWithSum(n, sum, arr);
    return 0;
}

*/

