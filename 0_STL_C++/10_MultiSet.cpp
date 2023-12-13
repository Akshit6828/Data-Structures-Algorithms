#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
- Stored everything in sorted order
- CAN STORE MULTIPLE OCCURRENCES OF ELEMENT
- Although a linear DS but inside implements a heap tree to sort itself
*/
void explainSets(){
    multiset<int> ms;

    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // Removes all occurrences of 1

    int count = ms.count(1); // Returns all counts of elements present

    auto it = ms.find(1); // First occurrence of 1
    ms.erase(it);


    // erase by [start, end) iterators
    // ms.erase(ms.find(1), ms.find(1) +2); // THROWS ERROR

    ms.erase(ms.find(1), next(ms.find(1), 2)); 
    // next() is used to obtain an iterator pointing to two positions past the element found by find(1)



}

int main(){
    explainSets();
    return 0;
}