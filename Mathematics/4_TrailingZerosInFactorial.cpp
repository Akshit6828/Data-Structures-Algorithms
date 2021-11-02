#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long



int CountZeroNaive(int n){ // O(n) due to outer loop of fact.
	int fact =1;
	for(int i =1 ;i<=n;i++)
		fact*= i;
	int res =0;
	while(fact%10==0){
	res++;
	fact/=10;
	}
	return res;
}

// Based on the fact that zero's are formed by numbers of 2's and 5's in prime factorization.
// Note: For any number no of 5's are always less than 2's.
// Thus we can calculate the no of 5's occuring in the prime factorization of number as 2*5= 10( One Zero)

int CountZeroEfficient(int n){ // O(LogN) solution. 
	int res =0;
	for(int i =5;i<=n;i= i*5)	
	res = res + n/i;
	
	return res;
}

signed main(){

	int n;
	cin>>n;
	cout<<"No of Zero's are: Naive: "<<CountZeroNaive(n)<<endl;
	cout<<"No of Zero;s are: Efficient: "<<CountZeroEfficient(n)<<endl;
	return 0;
}
