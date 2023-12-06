#include<bits/stdc++.h>
using namespace std;

void explainPair(){ // Pair is a part of utility library
    pair<int, int> p = {1,3};
    cout<<p.first <<" "<<p.second<<endl;

    // Nesting of a Pair
    pair<int, pair<int, int>> p2 = {1, {4,5}};
    cout<<p2.first<<" " <<p2.second.first << " "<<p2.second.second<<endl;

    // Array of Pair
    pair<int, int> arr[] = { {1,2} , {3,4} , {5,6}};
    cout<<arr[1].second<<endl;
}
int main(){
    explainPair();
}