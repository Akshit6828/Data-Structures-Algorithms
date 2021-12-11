#include<bits/stdc++.h>
using namespace std;


// Edge Test Case: 
// 1) If a number n is a perfect square.
// 2) If root(n) is a factor of N. Make sure not to print it 2 times.

// Note: For finding nearby root of any number N. Find the lowest nearby perfect square value.
// Eg: Root 50 approx =  Root(49) = 7.

void BruteForce(int n){

		for(int i = 1;i<=n;i++){
				if(n%i ==0){
					cout<<i<<" ";
				}
		}
		cout<<endl;
}
// 50: 1 2 5 10 25 50: 
void OptimizeOne(int n){// TC:O(Root(n)  + NlogN) [if in sorted form] else TC: O(sqrt(n)),  SC: O(N)
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
	sort(ans.begin(), ans.end()); // O(nLogn) extra as we need to output the answer in increasing sequence.
	for(int i:ans)
			cout<<i<<" ";
	cout<<endl;
}

void OptimizeFurther(int n){ // TC: O(n) SC: O(1)

		// Edge case: Square Numbers. Eg: 25
		// If the root(n) is a factor of N. Eg: 30.
		int i =0;
		for(i =1;(i*i)<= n;i++){ // We will traverse for ( i*i < N) and NOT i*i<=N because for the perfect square goes to second loop after incrementing i.  
				if(n%i==0)
						cout<<i<<" ";
		}

		i--; // For bringing back the incremented i back to = sqrt(i)

		for( ; i>=1 ; i--){ // No initialization.
				if(n%i==0 && i!=(n/i)) // use full for case where i = n/i = sqrt(n). Eg: 5 = 25/5 = root(5)
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
