#include <iostream>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

bool isPartitionPossibleWithSum(vector<int>& arr, int n, int sum, vector<vector<bool>>& dp) {
    // Initialization
    for (int j = 0; j <= sum; ++j)
        dp[0][j] = false;
    
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            int item = arr[i - 1];
            if (item <= j) {
                dp[i][j] = dp[i - 1][j - item] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) {
        return false;
    }

    int sumForSingleSubset = sum / 2;
    int n = nums.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(sumForSingleSubset + 1, false));
    return isPartitionPossibleWithSum(nums, n, sumForSingleSubset, dp);
}

// Example usage
int main() {
    vector<int> nums = {1, 5, 11, 5};
    
    if (canPartition(nums)) {
        cout << "Partition is possible" << endl;
    } else {
        cout << "Partition is not possible" << endl;
    }

    return 0;
}
