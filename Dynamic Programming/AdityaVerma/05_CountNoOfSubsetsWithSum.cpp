
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
    cout<<
    return 0;
}