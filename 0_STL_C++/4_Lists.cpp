#include<bits/stdc++.h>
using namespace std;

/*
Lists are almost same as vectors just with some front functions too (because its implemented as doubly linkedlist)
Usefull for such operations where you have to insert constantly at front or end.
LISTS ARE IMPLEMENTED INTERNALLY AS DOUBLY LINKED LIST

WHERE TO USE VECTOR VRS LIST?
So, if a collection changes very little (compared to accesses) or the changes are concentrated at the end, I'd use a vector.
If the number of changes is substantial (compared to accesses) and they're not at the ends, I'd use a list.

Some key differences:
Random access of elements is possible in vector BUT	not possible in list. Eg: l1[2] throws error
Iterators are valid to use if elements are added to or removed from the list.

Full article on: https://www.geeksforgeeks.org/difference-between-vector-and-list/
*/

void explainList(){
    // DECLARING LISTS
    list<int> l1;
    l1.push_back(1);
    l1.emplace_back(2); // Faster than push back

    l1.push_front(12);
    l1.emplace_front(9);

    // cout<<l1[2]; // Throws error since random access is not possible

    //************ REST ALL IS SAME AS VECTORS ONLY ***********************

}
int main(){
    explainList();
    return 0;
}