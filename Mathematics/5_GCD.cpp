#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define deb(x) cout << #x <<" = "<< x <<"\n" 

/*
Associated Problem with GCD:
TILING PROBLEM:
 - Given a room of A*B square matrix.
 - Find the size of the largest tile which can fill the room.
*/

/*
  IMPORTANT POINTS:
  A) GCD  = Largest number dividing both the numbers.
  B) GCD OF a,b is always <= min(a,b)

  IMPORTANT CASES FOR GCD:
  1) GCD OF 0(zero) with any number is the number itself. ie.. GCD(0,N) = N [OUR BASE CASE FOR RECURSIVE SOLUTION]
  2) One number divides other number. :-> ANS = min(A,B)
  3) IF A AND B are prime (7,13). :-> ANS = 1
  
  NOTE: IT DOESNT NOT MEAN IF GCD(A,B) =1 then THEY BOTH ARE PRIME ONLY. EG: 9,10 ARE COPRIMES.

*/

long int BruteForce(long int a, long int b){ // TC: O(min(A,B)) SC: O(1)

    int gcd = min( a, b); // Refer point B
    
    while(gcd>0){
      if(a%gcd ==0 && b%gcd ==0) // Checking if it divides both number
        break;
      else
        gcd--;
    }
  return gcd;

}

int EuclidGCDAlgo(long int a, long int b){
  
  /* EUCLID ALGO IS BASED ON FOLLOWING ASSUMPTIONS:
  1) If a>b then gcd(a,b) = gcd(a-b,b) = gcd(a%b,b) = gcd(remainder of a/b , b)
  2) If a<b then the else condition of this function will swap the numbers in first call.
  
  Short Proof: 
   -- Suppose g =  gcd(a,b) [PROVING LHS OF THE THEORUM]
      a=gx and b = gy AND gcd(x,y) = 1 {Always if g = gcd}
      if gcd(x,y) = 1 so solving equation:
      a = gx
      b = gy
      a-b = g(x-y)

  NOW PROVING: GCD(A-B, B ) is g. [PROVING RHS OF THE THEORUM]
      If Suppose (x-y) act as a gcd of a,b , so it would have been factor of a and b.
      Since gcd(x,y) =1 so (x-y) cannot be greater than g and thus gcd(a-b,b) = g only,
  */
  
  while(a != b){
    if(a>b)
    a = a-b;
    else 
    b = b-a;
  }
}

int EuclidOptimizedGCD(long int a, long int b){

}
int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    long int a,b;
    cin>>a>>b;
    cout<<BruteForce(a,b)<<endl;
    cout<<EuclidGCDAlgo(a,b)<<endl;

  }
  return 0;
}