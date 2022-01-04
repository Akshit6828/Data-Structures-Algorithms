#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


int iterate_left(vector<int> &x, int j, int a, int b){
    int count =0;
    for(int i = j-2; i>0;i-=2){
        //cout<<"Left index"<<i<<endl;
        if(a>x[i]&&b>x[i+1])
            count++;
        else if(a>x[i+1]&&b>x[i])
            count++;
    }
    return count;
}

int iterate_right(vector<int> &x, int j, int a, int b){
    int count =0;
    for(int i = j+2; i<x.size()-1;i+=2){
       //cout<<"Right index"<<i<<endl;
        if(a>x[i]&&b>x[i+1])
            count++;
        else if(a>x[i+1]&&b>x[i])
            count++;
    }
    return count;
}


void solve(){
    int n;
    cin>>n;
    vector<int> x;
    for(int i =0; i <(2*n); i+=2){
        int a,b;
        cin>>a>>b;
        x.push_back(a);
        x.push_back(b);
    }  
    int ans =0;
    for(int i =0; i <(2*n); i+=2){
        int a =x[i];
        int b = x[i+1];
        ans+=iterate_left(x,i, a,b);
        ans+=iterate_right(x,i,a,b);
    }
    cout<<ans;
}

int main(){
    boost;
    solve();
    return 0;
}