// Online C++ compiler to run C++ program online
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

// here n = no of items and not the index of element
int knapsackTopDown(int wt[], int val[], int totalWeight, int noOfItems, vector<vector<int>> &dp) {

	// Step 1: initialization
	for(int i = 0; i<= noOfItems; i++) {
		for(int j = 0; j<= totalWeight; j++) {
			if(i ==0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	// Replacing noOfItems(n) -> i and totalWeight(w) -> j
	for(int i = 1; i<= noOfItems; i++) {
		for(int j = 1; j<= totalWeight; j++) {

            // Referencing code from Memoized version
			// if(dp[i][j] != -1) { // it has already filled the desired value, lets skip it or this if block can be removed
				// Do nothing
			// }

			if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i-1][j - wt[i - 1]], // take
				               dp[i-1][j]);                   // not take

			}
			else {
				dp[i][i] = dp[i-1][j]; // not take
			}
		}

	}

	return dp[noOfItems][totalWeight];
}
int main() {
	cout<<"Enter total items and total knapsack weight"<<endl;
	int total_items, weightOfKnapsack;
	cin >> total_items >> weightOfKnapsack;

	int wt[total_items];
	int value[total_items];

	cout<<"Enter weight and value of the items"<<endl;
	for (int i = 0; i < total_items; i++) {
		cin >> wt[i] >> value[i];
	}

	vector<vector<int>> dp(total_items + 1, vector<int>(weightOfKnapsack + 1, -1));

	int ans = knapsackTopDown(wt, value, weightOfKnapsack, total_items, dp);
	printDp(dp);
	cout<<"max profit = "<<dp[total_items][weightOfKnapsack] << " or " <<ans; // Note both ans and dp[total_items][weightOfKnapsack] will store same ans

	return 0;
}