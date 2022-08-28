#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>

int sqrt(int x){// Infinte loop code

    int low = 1, high = x-1;
        
    while(low < high){ // {1,3}
        deb(low);
        deb(high);
       
        int mid = (low + (high - low) ) >> 1; // 
        int res = mid * mid;
        deb(mid);
        if(res < x)
            low = mid + 1;
        else if(res > x)
            high = mid - 1;
        else
            return mid;
    }

    return low;
}

int main(){
    int n;
    cin>>n;
    cout<<sqrt(n);
    return 0;
}