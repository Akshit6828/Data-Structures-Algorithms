// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

// here n = no of items and not the index of element
int knapsackRecursive(int wt[], int val[], int totalWeight, int n) {

  if (totalWeight == 0 || n == 0) {
    return 0;
  }

  if (wt[n - 1] <= totalWeight) {
    return max(val[n - 1] + knapsackRecursive(wt, val, totalWeight - wt[n - 1],n - 1),// take
               knapsackRecursive(wt, val, totalWeight, n - 1) // not take
    );
  } else {
    return knapsackRecursive(wt, val, totalWeight, n - 1); // not take
  }
}
int main() {
  int total_items, weightOfKnapsack;
  cin >> total_items >> weightOfKnapsack;

  int wt[total_items];
  int value[total_items];
  for (int i = 0; i < total_items; i++) {
    cin >> wt[i] >> value[i];
  }

  cout << knapsackRecursive(wt, value, weightOfKnapsack, total_items);

  return 0;
}