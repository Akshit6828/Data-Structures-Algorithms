#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n"

/* Corner Test Cases: 
	Check for negative numbers and `0`
	Check for integer overflow. `int` cant find variable length for more than 10 digits. Preffered 'long`.
*/
int solve_Iterative(long n){
    
    // TC: O(d) where d is len of number 'n'
    // SC: O(1)
    int count =0;
    if(n ==0) return 1;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}

int count_Digits_Recursive(long n){

    /* Recursive Function: T(n) = T(n/10) + 1;

    TC = O(Log10(N) 
    SC = O(d) where d is no of digits of N. 
    
    */
    if(n==0)
    return 0; // As for the case when no digit is left we need to return 0;
    else
    return 1 + count_Digits_Recursive(n/10);

}

int Lograthim_solution(long n){

    /*
    1) For an integer number that has n digits, it's value is between 10^(n - 1)(included) and 10^n,.
    so log10(number) is between n - 1(included) and n. 
    *** Eg: 2 digit numbers gonna be in range 10^(1)[Inclusive] to 10(2)[Exclusive].

    2)Then the function floor cuts down the fractional part(as log return double), leaves the result as n - 1. 

    3) Finally, adding 1 to it gives the number of digits.

    TC: O(Log10(n));
    SC: O(1)

    ***************************************BEST SOLUTION ***************************************
    */

   if(n==0) return 1; // Log(0) isnt defined as because you can never get zero by raising anything to the power of anything else.
   if(n<0)
    n*=-1; // Log of negative isnt defined....
    return floor(log10(n) + 1);
}

int main(){
    //boost;
    int t;
    cin>>t;
    while(t--){
    long n;
    cin>>n;
    cout<<"Iterative Sol: "<<solve_Iterative(n)<<endl;
    cout<<"Recursive Sol: "<<count_Digits_Recursive(n)<<endl;
    cout<<"Log Solution: "<<Lograthim_solution(n);
    }
    return 0;
}
