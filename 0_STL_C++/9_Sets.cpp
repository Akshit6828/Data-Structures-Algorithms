#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
- Stored everything in sorted order
- Stored everything unique
- Although a linear DS but inside implements a heap tree to sort itself
*/
void explainSets(){
    // Initialize set passing initializer
   // list as an argument to the
   // default constructor
   set<int>New_set({4, 3, 9, 2, 0, 6});

   // Initialize a vector of integers
    vector<int>old_arr = {4, 1, 8, 2, 9};
   
    // Adding these elements 
    // stored in the vector
    set<int>New_set2(old_arr.begin(),old_arr.end());
    
    set<int> st;

    set<int,greater<int>> decreasingSet; // TO MAKE A SET IN DECREASING ORDER

    st.insert(2);
    st.insert(1);
    st.emplace(4);
    st.insert(3);
    st.insert(3); // Wont store again, as 3 is already there
    st.insert(6);
    st.insert(17);
    st.insert(8);
    st.insert(9);
    st.insert(25);
    

    auto it = st.find(2); // Returns an iterator pointing towards this value

    auto it  = st.find(24); // Returns st.end() iterator

    st.erase(2); // Deletes 2 and maintain order

    int cnt = st.count(1); // Returns 1 if present, else returns 0

    auto it = st.find(3);
    st.erase(it);

    auto it1 = st.find(6);
    auto it2 = st.find(9);

    st.erase(it1, it2); // Erases between 6 to 9


    // st = { 1, 2, 4, 4, 5, 5, 9, 17}
    // ind =  0  1  2  3  4  5  6  7
    // upper and lower bound only works, if the container is sorted
    auto it1 = st.lower_bound(4); //  it1 = 2
    // Points to first occurrence of a  number >=4
    // lower_bound() returns the iterator of the first such value

    auto it2 = st.upper_bound(5); // it2 = 6 
    // Points to first occurrence of a number > 5
    //upper_bound() returns the iterator of immediate next index which is greater element than the element

    // PRINTING SET
    for (auto element : st) {
        std::cout << element << " ";
    }

}

int main(){
    explainSets();
    return 0;
}