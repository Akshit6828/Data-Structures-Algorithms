#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// 1 2 3 4 5 6 7 8 9 10
// sqrt(23)--> (0 + 10)/2 = 5 --> (0 + 4)/2 = 4(ans) --> 5 + 4 (Exit loop) 
// sqrt(48)--> (0 + 10)/2 = 5(ans) --> (6 + 10)/2 = 8 --> (6 + 7)/2 = 6(ans) --> (7 + 7)/2 = 7 --> (6 +7) Exit loop
int floorSqrt(int n){

    int low = 0, high = n;
    int ans = -1;

    while(low <=high){
        int mid = (low + high) >>1;
        int sqrtMid = mid * mid;

        if(sqrtMid > n){
            high = mid - 1;
        }
        else if(sqrtMid < n){
            ans = mid;
            low = mid + 1;
        }
        else
        return mid;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<floorSqrt(n);
    return 0;
}