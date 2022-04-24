#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


// Edge case:0, 1 digit number and -ve numbers
// Checking based on the fact that for any num xy we have x*10 +y= xy;


bool checkPalindrome(int n){ // TC: O(d) where d is length of digit.
	
	if(n<=9&&n>=0) return true; // Condition for : Every Single number is a palindrome.
		
	int rev =0;// Better to initialize rev with 0 to even check if 0 is palindrome or not even if above case isnt defined.

	int num = n;

	while(num>1){
	int lastDigit = num%10; // Finding the last digit
	rev = rev*10 + lastDigit; // 12 = 0*10 + 2 = '2' ---> 2*10 + 1 ='21' { 12---21 for checking palindrome}
	num = num/10; // Removing the last digit
	}

	return (rev == n);
}

void solve(){
	int n;
	cin>>n;
	string ans;
	ans = checkPalindrome(n)==0?"False":"True";
	cout<<ans<<endl;        
}

int main(){
	boost;
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}