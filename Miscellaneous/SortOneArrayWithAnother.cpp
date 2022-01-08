#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


bool cmp(int i, int j, vector<int> &b){
    if(b[i]<b[j])
        return true;
    else
    return false;
}

void solveArraySort(){
      int n; // Size of array
      cin>>n;
      vector<char>  a(n);
      vi b(n, -1);
        for(int i = 0; i<n;i++){
            char ch;
            int num;
            
            cin>> ch;
            cin>>num;
            a.push_back(ch);
            b.push_back(num);
        }
        for(auto i: a)
        cout<<i<<" ";
    sort(a.begin(),a.end());
}

bool cmp(int a, int b){
    return a - b;
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