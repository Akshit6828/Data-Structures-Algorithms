#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>

class Solution {
public:


    int totalMoneyOptimize(int n){ // TC: O(1) Sc: O(1)
        int sum = 0;
        int full = n/7;
        int remaining = n%7;
        
        sum+= full*28 + full *(full- 1 ) * 7/2;
        sum+=(remaining*(remaining+1)/2)+full*remaining;
        
        return sum;
    }

    int totalMoneyOptimizeSecond(int n){ // TC: O(1) SC: O(1)
    // Using concept of 2D matrix:
        int row = (n - 1) / 7;
        int col = (n - 1) % 7;
        return row * 28 + (7 * (row - 1) * row + (col + 1) * (2 * row + 2 + col)) / 2;
    }

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
        cout<<obj.totalMoney(15)<<endl;
        cout<<obj.totalMoneyOptimize(15)<<endl;
        cout<<obj.totalMoneyOptimizeSecond(15)<<endl;
    }
    return 0;
}