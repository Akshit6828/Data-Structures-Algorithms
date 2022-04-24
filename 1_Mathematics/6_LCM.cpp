#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


int gcd(long int a, long int b){
    if(b == 0)
    return a;
    else
    return gcd(b,a%b);
}

/* IMPORTANT POINTS ON LCM:
1) LCM  = Smallest number which is divisible by both number(a,b). or First(Least) Common Multiple of A and B.
2) LCM  = greater or equall to larger of A and B.

IMPORTANT CASES:
1) If one number divides other: LCM = Max(A,B)
2) If botg


*/

int BruteForce(long int a, long int b){ // TC: O((a*b) - min(a,b)) SC: O(1)
    
    if(a==0) return 0;
    if(b==0) return 0;
    int i = min(a,b); // LCM is smaller than or equal to min(a,b). 

    int lcm = i; //Thus it is better to initialize it with min.
    
    for(; i<=(a*b);i++){
        if(i%a ==0 && i%b==0){
            lcm = i;
            break;
        }
    }
    return lcm;
}

int optimizeLCM(long int a, long int b){
    if(a==0) return 0;
    if(b==0) return 0;
    /* Based on the fact that a*b = LCM(a,b) * GCD(a,b);
    LCM = a*b/GCD(a,b)
    */
    return ((a*b)/gcd(a,b));

}


int main(){
    boost;
    int t;
    cin>>t;
    while(t--){
        long int a,b;
        cin>>a>>b;
        cout<<"Brute Force Solution: "<<BruteForce(a,b)<< endl;
        cout<<"Optimized Solution: "<<optimizeLCM(a,b)<< endl;


    }
    return 0;
}