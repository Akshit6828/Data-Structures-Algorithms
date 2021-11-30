#include<bits/stdc++.h>
using namespace std;


// Edge Test Case: 
// 1) If a number n is a perfect square.
// 2) If root(n) is a factor of N. Make sure not to print it 2 times.

void BruteForce(int n){

		for(int i = 1;i<=n;i++){
				if(n%i ==0){
					cout<<i<<" ";
				}
		}
		cout<<endl;
}

void OptimizeOne(int n){// TC:O(Root(n)) SC: O(N)
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

void OptimizeFurther(int n){

		// Edge case: Square Numbers. Eg: 25
		// If the root(n) is a factor of N. Eg: 30.
		int i =0;
		for(i =1;(i*i)<= n;i++){ // We will traverse for ( i*i < N) and NOT i*i<=N because for the perfect square goes to second loop after incrementing i.  
				if(n%i==0)
						cout<<i<<" ";
		}

		i--;

		for( ; i>=1 ; i--){ // No initialization.
				if(n%i==0 && i!=(n/i))
					cout<<(n/i)<<" ";
		}
}

int main(){
int t;
cin>>t;
	while(t--){
		int n;
		cin>>n;
		BruteForce(n);
		OptimizeOne(n);
		OptimizeFurther(n);
	}
}
