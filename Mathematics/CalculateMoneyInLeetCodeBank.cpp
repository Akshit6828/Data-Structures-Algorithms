#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>

class Solution {
public:
    int totalMoney(int n) { // TC: O(n/7) SC: O(1)
        
    /* 
    n = 24
    
    1 + 2 + 3 + 4 + 5 + 6 + 7 =  7 * 7+1/2  - 0*1/2 =>
    2 + 3 + 4 + 5 + 6 + 7 + 8 =  8 * 8+1/2  - 1*2/2 =>
    3 + 4 + 5 + 6 + 7 + 8 + 9 =  9 * 9+1/2  - 2*3/2 => 
    4 + 5 + 6
    */
     if(n<=7) return n*(n+1)/2;
     else
     {
         /*
         1 + 2 + 3 + 4 + 5 + 6 + 7 = 7*7+1/2
         2 + 3 + 4
         */
         int count = n/7;
         int remaining_days = (n- 7*count);
         int ans =0;
         int prev_amount = 7;
         for(int i =1;i<=count;i++){
             ans+=((prev_amount * (prev_amount+1))/2 - (i*(i-1))/2);  
             prev_amount++;
         }
         //cout<<ans<<" Is After 2st Loop"<<endl;
         //cout<<"Prev Amount = "<<prev_amount<<endl;
         
         int firstLeftDay = (prev_amount - 7 + 1);
         for(int i = firstLeftDay; i< (firstLeftDay + remaining_days);i++)
             ans+=i;
         return ans;
     }
        
        
    }
};

int main(){
    boost;
    Solution obj;

    int t;
    cin>>t;
    while(t--){
        cout<<obj.totalMoney(3)<<endl;
        cout<<obj.totalMoney(10)<<endl;
        cout<<obj.totalMoney(24)<<endl;
    }
    return 0;
}