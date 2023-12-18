#include<bits/stdc++.h>
using namespace std;

// Printing all prime factor of N in ascending order.
// Edge Case: If a number is a prime
bool isPrime(int n){
	if(n<=1) return false;
	if(n==2||n==3) return true;
	if(n%2==0||n%3==0) return false;
	for(int i = 5;i*i<=n;i+=5){
			if(n%i==0|| n%(i+2)==0)
				return false;
	}
	return true;
}
void BruteForce(int n){// TC: O(N * Sqrt(N) * Log(n))= O(N^3/2 Log(n)) SC: O(1)
	bool FoundPrimeFactors = false;
	for(int i =2;i<=n;++i){ //TC:O(n),  <= because if the number is prime, it will have itself as one of the factors. Eg: For 13, it will only print 13.
		if(isPrime(i)){ //TC: O(Root(n)
			int curPrimePower = i;
			while(n%curPrimePower==0){ //TC: Log(n)
				FoundPrimeFactors = true;
				cout<<i<<" ";
				curPrimePower = curPrimePower * i; // Eg: 2, 2^2, 2^3, ....
			}
		}
	}
	if(!FoundPrimeFactors)
		cout<<"No prime factors found"<<endl;	
	else
	cout<<endl; // For printing next test case in new line.
}


void OptimizeOne(int n){ // TC:O(Sqrt(n)*Log(n))  SC: O(1)
// Based on facts:
// 1) Factors occur in pair{x, n/x}.
// 2) Any number can be written as the product of primes.
	
// Algo:1) Find the first prime factor  and if there exist any prime number as factor then it will be in range of O- Root(n)
// 2) Once we find the prime factor, keep dividing the number N, until it is divinding N and then assign new value of number left to N. 
// 		Eg: First pass: N = 2^2 * 3  * 7
// 	 		Second pass: N = 3*7 (New N has been reduced by removing previous factors)
// 3) Find the next prime and repeat	
	
	if(n<=1) return;
	for(int i =2;i*i<=n;i++){
		while(n%i==0){
				cout<<i<<" ";
				n = n/i;
		}
	}
	if(n>1){// For Edge case if the last prime number has power 1. Eg: 2^2 *3^3  * 7. So at last 4*4<7 will be false. Thus explictly checking if n>1. It will only execute in above case or if the N is a prime number.
		cout<<n;
	}
	cout<<endl;
	
}

void OptimizeFurther(int n){// TC: O(root(n)) if ignoring inner LOG(N) factor because it will run at max root(n) times.  SC: O(1) 
// Furthur optimization is based on the fact that if we explicitly check for 2 and 3. We can save many iterations.
	
	bool foundPrimeFactors = false;
	if(n<=1) return;
	while(n%2==0){
			foundPrimeFactors = true;
			cout<<2<<" ";
			n = n/2;
	}
	while(n%3==0){
			foundPrimeFactors = true;
			cout<<3<<" ";
			n = n/3;
	}

	for(int i = 5;i*i<=n;i+=6){
	// Checks include n%i  and n*(i+2) only.
	while(n%i ==0){
			foundPrimeFactors = true;
			cout<<i<<" ";
			n = n/i;
	}
	while(n%(i+2)==0){
			foundPrimeFactors = true;
			cout<<i<<" ";
			n = n/(i+2);
	}
	}
	if(n>3){// It is good to check for n>3 as 2 and 3 have been explicitly checked above.
	cout<<n;
	foundPrimeFactors = true;
	}
	if(!foundPrimeFactors)
			cout<<"No prime factors found"<<endl;
	else
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
	OptimizeFurther(n);
	}
}
