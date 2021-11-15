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

	/* ISSUES:
	1) We are calculating the whole factorial of a number without knowing it will contain any O or not
	2) Causes major overflow such that any factorial of 19 digits cannot be stored in datatype.
	*/
}



int CountZeroEfficient(int n){ // O(Log5(N)) or LogN solution. 

	/* 

	INTERESTING FACTS FOR EFFECTIVE SOLUTION:
 	1) Zero's are formed by numbers of 2's and 5's in prime factorization.
 	2) For any number no of 5's are always less than 2's.
	--- Thus we can calculate the no of 5's occuring in the prime factorization of number as 2*5= 10( One Zero)
 	3) There gona be atleast floor(n/5) number of 5's because there are other numbers such as 25 which have 2 5's as prime factor.
 	4) It solves major issues that we arnt calcuating whole factorial 
 	*/
	
	int res =0;
	for(int i =5;i<=n;i= i*5)	
	res = res + n/i; 
	
	/* 
	'n/i' because if we want to get 2 times 5 from 25 as 25 = 5*5.
	So first time 25/5  ---> Eliminated 1st 5's.
	And Second time 5/5 ---> Eliminated 2nd 5.
	*/
	return res;

	/* ****************      BEST SOLUTION     ******************************/
}



signed main(){

	int n;
	cin>>n;
	cout<<"No of Zero's are: Naive: "<<CountZeroNaive(n)<<endl;
	cout<<"No of Zero;s are: Efficient: "<<CountZeroEfficient(n)<<endl;
	return 0;
}
