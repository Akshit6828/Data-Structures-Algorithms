#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


bool myCmp(pair<int, int> a, pair<int,int> b){
    return a.second < b.second;
}
void solve(){
      vector<pair<int, int>> activities;
      int n;
      cin>>n;

      // Inputting vector of pairs
      for(int i = 0;i<n;i++){
          int a,b;
          cin>>a>>b;
          activities.push_back(make_pair(a,b));
      }

      /*for(auto i: activities){
        cout<<i.first<<" "<<i.second<<" ";
      }*/

      sort(activities.begin(), activities.end(), myCmp);

      int ans = 1;
      int prev = 0;
      for(int i = 1; i<n;i++){
          if(activities[i].first >= activities[prev].second){
              prev = i;
              ans++;
          }
      }

      cout<<"Total Activites can be done are: "<<ans<<endl;

}

int main(){
    boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}