#include<bits/stdc++.h>
using namespace std;

// -- Sol: 1
void BruteForce(int n){ // TC: O(N*N) SC: O(1)
	for(int i = 2;i<=n;i++){
		bool numIsPrime = true;
		for(int  j = 2; j<i; j++){
			if(i%j ==0){
				numIsPrime = false;
				break;
			}
		}
		if(numIsPrime)
		cout<<i<<" ";

	}	
}

// -- Helper Function used by Sol 2, 3, 4 for checking if num is prime or not.
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

// -- Sol: 2
void optimize1(int n){ // TC: O(N* Sqrt(n) )
	for(int i = 2;i<=n;i++){
		if(isPrime(i)) // Checking isPrime in Sqrt(N)
			cout<<i<<" ";
	}
}




// -- Sol: 3 
void sieveOfErathosisUsingVector(int n){ // TC(NLog(LogN)) [ By HP Series proved on wikipedia] SC: O(N)
	vector<bool> primesArr(n+1, true);

	for(int i =2; (i*i)<=n; i++){ // Need to check until root(n) because suppose if n = 96 it will be made false by 2. Thus, if suppose Num = 97(a prime num) then it wont be made false by any num till root(n).
	// So its better to check till Root(n) only.

		if(isPrime(i)){ 
			for(int j = 2*i; j <=n; j+=i){ // 2:-> 4  6  8 ... all false
				primesArr[j] = false;      // 3:-> 6  9  12 ... all false
			}
		
		}
	
	}

	// Printing the true values from primesArr.
	for(int i = 2;i <=n; i++){
		if(primesArr[i])
			cout<<i <<" ";
	}
}

void sieveOfErathosisUsingBitSet(int n){ // TC(NLog(LogN)) [ By HP Series proved on wikipedia] SC: O(N)[Optimized by BitSet]

	bitset<1000005> primesSet; // Optimization for space.
	primesSet.set(); // Sets all bits to 1.
	primesSet[0] = primesSet[1] = 0;

	for(int i = 2; i*i <= n; i++){
		if(isPrime(i)){
			for(int j = i*i; j<=n ; j = j+i){ // Optmization that the first number which isnt checked by previous one is i*i;
			// Reason: if i = x*y and x!=y so either x is smaller than y or vice versa. Thus the smaller of x or y would have already been checked before
			// Eg: For N = 5 next num is 10. So 10 = 5*2 Means it is already checked by 2 ie. 2,4,6,8,10. So we can direclty see the first num to be checked is 25 only.
				primesSet[j] = 0;
			}
		}
	}

	for(int i = 2; i<=n;i++){
		if(primesSet[i])
			cout<<i<<" ";
	}

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		BruteForce(n); cout<<endl;
		optimize1(n); cout<<endl;
		sieveOfErathosisUsingVector(n); cout<<endl;
		sieveOfErathosisUsingBitSet(n); cout<<endl;
	}
return 0;
}
