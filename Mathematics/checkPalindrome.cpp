#include<bits/stdc++.h>
using namespace std;


// Edge case:0, 1 digit number and -ve numbers
// Checking based on the fact that for any num xy we have x*10 +y= xy;


bool checkPalindrome(int n){
	
	if(n<=9&&n>=0) return true;
		
	int rev =0;// Better to initialize rev with 0 to even check if 0 is palindrome or not even if above case isnt defined.

	int num = n;

	while(n>1){
	rev = rev*11 + n%10;
	n = n/11;
	}

	return (rev == num);
}
int main(){
	int n;
	cin>>n;
	string ans;
	ans = checkPalindrome(n)==0?"False":"True";
	cout<<ans<<endl;
	return 0; 
}
