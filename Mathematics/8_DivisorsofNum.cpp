#include<bits/stdc++.h>
using namespace std;


void BruteForce(int n){

		for(int i = 1;i<=n;i++){
				if(n%i ==0){
					cout<<i<<" ";
				}
		}
		cout<<endl;
}

void OptimizeOne(int n){
	// It is based on 2 facts:
	// 1) Divisors of the number are always in pair.
	// 2) One of the divisor in every pair is <= Root(n)
	vector<int> ans;
	for(int i =1;i*i<=n;i++){
		if(n%i ==0){
			ans.push_back(i);

		if((n/i)!= i)
			ans.push_back(n/i);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i:ans)
			cout<<i<<" ";
	cout<<endl;
}

int main(){
int t;
cin>>t;
	while(t--){
		int n;
		cin>>n;
		BruteForce(n);
		OptimizeOne(n);
	}
}
