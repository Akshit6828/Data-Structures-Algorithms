// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct compare
{
    int val;
    compare(int const &i): val{i} {}
 
    bool operator()(const int &i) const {
        return (i == val);
    }
};
int main() {
    // Write C++ code here
    vector<int> v = { 7, 2, 2, 4, 3, 2, 6 };
    vector<pair<int, int>> freq;
     for(auto x: v){
         int f = count_if(v.begin(), v.end(), compare(x));
         if(freq.find(freq.begin(), freq.end(),x}) == freq.end())
            freq.push_back({x,f});
     }
     
     for(auto it: freq){
         cout<<it.first<<" "<<it.second<<endl;
     }

    return 0;
}