#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>



string solve(){
   int n;
   cin>>n;
   if(n&1)
    return to_string(n*2);
   else
   return NULL;

}

int main(){
    boost;
    int t;
    cin>>t;
    while(t--){
    string res = solve();
    if(res == "NULL")
        cout<<"Even wrong value inputted\n";
    else
    cout<<res<<" ";
    }
    return 0;
}