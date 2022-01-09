#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>

bool cmpValues(pair<int, int> a, pair<int, int> b){
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1 > r2;
}

void solve(){
      int n , capacity;
      cin>>n>>capacity;

      vector<pair<int, int>> items;
      for(int i =0;i<n;i++){
          int value,weight;
          cin>>value>>weight;
          items.push_back(make_pair(value,weight));
      }      

      sort(items.begin(), items.end(),cmpValues);
    cout<<"Sorted Array become\n";
      for(auto i: items)
      cout<<i.first<<" "<<i.second<<endl;

      int curCapacity = capacity;
      double ans = 0;
      for(int i =0;i<n;i++){

          if(items[i].second<=curCapacity){
              curCapacity -= items[i].second;
              ans+=(double)items[i].first;
              cout<<i<<"th Item added "<<items[i].first<<" to answer"<<endl;
          }
          else{
              ans+= (items[i].first * ((double)curCapacity/items[i].second));
              //curCapacity -=  (double)(items[i].second - curCapacity)/items[i].second;
               cout<<i<<"th Item added "<<(items[i].first * (double)(curCapacity/items[i].second))<<" to answer"<<endl;
              break;
          }
      }
      cout<<"\nMax Weight  = "<<ans<<endl;
}

int main(){
    boost;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}