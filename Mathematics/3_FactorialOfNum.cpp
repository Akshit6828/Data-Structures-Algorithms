#include<bits/stdc++.h>
using namespace std;
#define int long long

// Edge case: O and Large Numbers.



int IterativeSol(int n){
		int ans =1;
		for(int i =1;i<=n;++i){
				ans*=i;
		}
		return ans;
}

int RecursiveSol(int n){
		if(n ==0 || n ==1)
				return 1;
		return n*RecursiveSol(n-1);
}

signed main(){
	int n;
	cin>>n;
	cout<<IterativeSol(n); // O(n) time and O(1) Aux-Space
	cout<<RecursiveSol(n); // O(n) time and O(n) Aux-Space(Stack Space)
		
	return 0; 
}
