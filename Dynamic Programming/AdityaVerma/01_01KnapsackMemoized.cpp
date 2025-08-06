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
int knapsackMemoized(int wt[], int val[], int totalWeight, int noOfItems, vector<vector<int>> &dp) {

	if (totalWeight == 0 || noOfItems == 0) {
		return dp[noOfItems][totalWeight] = 0;
	}

	if(dp[noOfItems][totalWeight] != -1) {
		return dp[noOfItems][totalWeight];
	}

	if (wt[noOfItems - 1] <= totalWeight) {
		return dp[noOfItems][totalWeight] = max(
            val[noOfItems - 1] + knapsackMemoized(wt, val, totalWeight - wt[noOfItems - 1],noOfItems - 1,dp),// take
            knapsackMemoized(wt, val, totalWeight, noOfItems - 1, dp) // not take
            );
	} else {
		return dp[noOfItems][totalWeight] = knapsackMemoized(wt, val, totalWeight, noOfItems - 1, dp); // not take
	}
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

	int ans = knapsackMemoized(wt, value, weightOfKnapsack, total_items, dp);
	printDp(dp); // just for printing DP matric
	cout<<"max profit = "<<dp[total_items][weightOfKnapsack] << "or " <<ans; // Note both ans and dp[total_items][weightOfKnapsack] will store same ans

	return 0;
}