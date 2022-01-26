#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>



void solve(){
    int n = 5;
    int m = 6;
    vector<vector<int>> v(5);
     
      v[0][0] = 2;
      deb(v.size());
      int c=0;
      int i  = 0;
      while(c<5){
          v[c][i] = (c+1);
          i++;
          v[c][i] =(c+2);
      }    

      for(auto &level: v){
            for(auto &node: level)
                cout<<node<<" ";
            cout<<endl;
    }

    // vector<int> temp;
     // temp.push_back(2);
}

int main(){
    //boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}