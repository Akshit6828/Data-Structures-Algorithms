#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define ll long long 
#define deb(x) cout << #x <<" = "<< x <<"\n" 
#define vi vector<int>


int rightWindow(vector<int> &x, int s, int k){
    int minSum = INT_MAX;
    int indx = 0;
    for(int i = s;i<=(x.size() -k);i++){
        int curSum =0;
        for(int j = i; j<(i+k); j++){
            curSum+=x[j];
        }
        if(minSum >= min(minSum, curSum)){
            minSum = min(minSum, curSum);
            indx = i;
        }
    }
    return indx;
}

int leftWindow(vector<int> &x, int s, int k){
    int minSum = INT_MAX;
    int indx = 0;
    for(int i = s;i>=(k-1);i--){
        int curSum =0;
        for(int j = i; j>=0; j++){
            curSum+=x[j];
        }
        if(minSum >= min(minSum, curSum)){
            minSum = min(minSum, curSum);
            indx = i;
        }
    }
    return (indx-k+1);
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> x;
    for(int i =0; i<n;i++){
        int l;
        cin>>l;
        x.push_back(l);
    }
    int l,r;
    for(int i =0;i<=(x.size() -k);i++){
        leftWindow(x,i+k,k);
    }

}

void solveSort(){
    int n,k;
    cin>>n>>k;
    vector<int> y;
    for(int i =0; i<n;i++){
        int l;
        cin>>l;
        y.push_back(l);
    }
    vector<int> x = y;
    sort(x.begin(), x.end());
    int sum1 =0, sum2 = 0;
    int val1 = x[0];
    int val2 = x[k];
    for(int i =0;i<k;i++){
        sum1+=x[i];
    }
    for(int i =k;i<2*k;i++){
        sum2+=x[i];
    }
    //cout<<"S1"<<sum1<<"S2"<<sum2<<endl;
    //cout<<"VAL 1 = "<<val1<<" VAl 2 = "<<val2<<endl;
    int l =0,r = 0;
    for(int i =0;i<n;i++){
        if(y[i] == val1){
            int curSum = 0;
            for(int j = i;j<i+k;j++){
                curSum+=y[j];
            }
            //cout<<"VAL 1 CUR Sum for "<<i<<"th Index  = "<<curSum<<endl;
            if(curSum == sum1)
            l = i;
        }
        if(y[i] == val2){
            int curSum = 0;
            for(int j = i;j<i+k;j++){
                curSum+=y[j];
            }
            //cout<<"VAL 2 CUR Sum for "<<i<<"th Index  = "<<curSum<<endl;
            if(curSum == sum2)
            r =  i;
        }
    }

    if(l>r)
    cout<<r+1<<" "<<l+1;
    else
    cout<<l+1<<" "<<r+1;

}
int main(){
    boost;
    solveSort();
    return 0;
}