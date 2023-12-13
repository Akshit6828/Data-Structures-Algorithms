#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void explainMap(){
      map<int, string> mp;
      /**
       * Map stores unique keys in sorted order
       * 
       */
      map<pair<int, int> , int > mp2;
      map<int, pair<int, int>> mp3; // Map can be of anything

      mp[1]  = "Akshit";
      mp[2] = "Amrita";
      mp.emplace(3, "Sunita");
      mp.insert({4, "dad"});

      for(auto it: mp)
        cout<<it.first <<" "<<it.second<<endl;

    cout<<mp[1];
    cout<<mp[9]; // Prints nothing since value is not there

    map<int, int> mpp;
    cout<<mpp[3]; // Prints 0 since value is not there

    map<int, bool> mppp;
    cout<<mppp[3]; // Prints 0 since value is not there. So default value of bool is also int


    // ACCESSING MAP using ITERATORS
    // auto it = mp.find(2);
    // cout<<(it->second);

    auto it = mp.lower_bound(2); // returns it to index where mp[i] >= 2. ie.. [2,Amrita]
    cout<<it->first<<" -- "<<it->second<<" --------"<<endl;

    auto itr = mp.upper_bound(2); // returns it to index where mp[i] > 2. ie.. [3, Sunita]
    cout<<itr->first<<" -- "<<itr->second<<" --------"<<endl;

    auto itt = mp.upper_bound(4); // Prints Nothing
    // cout<<itt->first<<" -- "<<itt->second<<" --------"<<endl;

}

void explainMultipMap(){
    // Same everthing just multiple keys can be used
    // mp[key] only can be used here
}

void explainUnorderedMap(){
    // Map which doesnot have sorted order
    // Accessing is in O(1) time generally
    
}
int main(){
    explainMap();
    return 0;
}