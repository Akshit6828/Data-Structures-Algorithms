#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>

bool cmp(int a, int b){
    return a - b;
}
void solveArraySort(){
      int n; // Size of array
      cin>>n;
      map<char, int> mp;
        for(int i = 0; i<n;i++){
            char ch;
            int num;
            cin>> ch;
            cin>>num;
            mp.insert({a,b});

        }
        for(auto i: a)
        cout<<i<<" ";
    sort(a.begin(),a.end(), cmp);
}


int main(){
    boost;
    int t;
    cin>>t;
    while(t--){
    solveArraySort();
    }
    return 0;
}