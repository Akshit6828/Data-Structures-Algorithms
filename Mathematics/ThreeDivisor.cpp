#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


class Solution {
public:
    
    bool isPrime(int n){
        if(n==2||n==3) return true;
        if(n%2==0||n%3==0)
            return false;
        for(int i = 5;(i*i)<=n;i+=5){
        if(n%i ==0 || n%(i+2) == 0){
            return false;
            break;
        }
        }
        return true;
    }
    
    bool isThree(int n) {
        
    if(n<3) 
        return false; 
        
    long double sqr = sqrt(n);  
    if((int)sqr == sqr && isPrime(sqr))   // Checking if the number is a square of a prime number   
        return true;
    else return false;
        
    }
};

int main(){
    boost;
    Solution obj;

    int t;
    cin>>t;
    while(t--){
        cout<<obj.isThree(3)<<endl;
        cout<<obj.isThree(12)<<endl;
        cout<<obj.isThree(25)<<endl;
        cout<<obj.isThree(90)<<endl;
        cout<<obj.isThree(50)<<endl;
    }
    return 0;
}