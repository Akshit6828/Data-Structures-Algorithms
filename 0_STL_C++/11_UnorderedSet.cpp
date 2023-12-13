#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
- DOESNOT STORES IN SORTED ORDER
- Stored everything unique
*/
void explainUnorderedSets(){
    // Initialize set passing initializer
   // list as an argument to the
   // default constructor
   unordered_set<int>st1({4, 3, 9, 2, 0, 6});

   // Set from a vector
    vector<int>vt = {4, 1, 8, 2, 9};
    unordered_set<int>st2(vt.begin(),vt.end());
    
    unordered_set<int> st;
    st.insert(1);

    /*
    - upper_bound() and lower_bound() doesn't works since no sorted order is maintained
    - REST ALL functions are same.
    */
   /*
   SETS vrs UNORDERED_SET
   In C++, both std::set and std::unordered_set are associative containers that store unique elements. However, they have some key differences in terms of their underlying data structures and performance characteristics.

1) Ordering:

std::set: Elements in a set are always sorted in a specific order (by default, in ascending order). This ordering allows for efficient searching, insertion, and deletion of elements.
std::unordered_set: Elements in an unordered_set are not sorted. Instead, they are stored in a way that allows for fast retrieval of individual elements. The order of elements is not guaranteed to be any specific order.

2) Underlying Data Structure:

std::set: Typically implemented as a balanced binary search tree (e.g., Red-Black Tree). This ensures logarithmic time complexity for operations like insertion, deletion, and search.
std::unordered_set: Implemented using a hash table. This allows for constant time average complexity for insertion, deletion, and search operations.

3) Performance:

std::set: Operations on a set have a logarithmic time complexity, making them generally slower than unordered sets for large datasets.
std::unordered_set: Provides constant average time complexity for most operations, making it faster than std::set for many scenarios, especially when the dataset is large.

4) Iterator Validity:

std::set: Iterators remain valid even after insertion or deletion of elements, as the underlying structure ensures stability.
std::unordered_set: Iterators might be invalidated if elements are inserted or deleted, as the hash table might be resized.

5) Memory Overhead:

std::set: Typically has a higher memory overhead compared to std::unordered_set due to the structure needed for maintaining order.
std::unordered_set: Tends to have lower memory overhead.

** WHEN AND WHAT TO CHOOSE WHEN?
Choosing between std::set and std::unordered_set depends on the specific requirements of your application. 
If you need ordered elements or stable iterators and can tolerate slightly slower performance, std::set may be a good choice.
If you prioritize fast average-case performance for operations like insertion and search, and the order of elements doesn't matter, std::unordered_set might be more suitable.

*/
}

int main(){
    explainUnorderedSets();
    return 0;
}