#include<bits/stdc++.h>
using namespace std;

/*
Vectors are Dynamic arrays whose size can be extended or decreased.
Usefull for such operations where size can be increased or decreased.
VECTORS ARE IMPLEMENTED INTERNALLY AS SINGLY LINKED LIST

*/
void explainVector(){

    // DECLARING VECTORS
    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(2); // Faster than push back

    // Vector of pair
    vector<pair<int, int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(3,4);

    // Predefined values in vector
    vector<int> v3(5, 12); // Vector with 5 indexes having value = 12

    // vector with 5 indexes having 0 or -1 value depending on compiler
    vector<int> v4(5);

    // Declaring one vector from another
    // vector<int> v5(v2); // Runtime error since structure of v5 and v2 isnt same
    vector<int> v5(v3);
    for(auto x: v5)
        cout<<x<<endl;

    
    // ACCESSING VECTOR VALUES
    
    // Without iterator
    cout<<v1[1]; // Using index
    cout<<v1.at(1); // Using at() function

    // Iterator
    vector<int>::iterator myIterator = v3.begin(); // Note this myIterator is pointer towards my memory address of the first element and not the value.
    // Syntax: DataStructure + :: + iterator + iterator_name = definedDS.begin(); or any position
    myIterator++;
    cout<<*(myIterator);

    // Different iterators options available
    vector<int>::iterator it1 = v3.end(); // "end()" points to a memory location which points AFTER the last index and NOT AT THE LAST INDEX. it1-- will point to last element and it1 will not point.

    // vector<int>::iterator it = v3.rend(); // first reverse the array and points to end. it basically points on left of first index. if it2-- it will bring that iterator towards right now (original towards the end of array)

    // vector<int>::iterator itrr = v3.rbegin(); // first reverse the array and point to the begin(). It basically points to the last element of the array. it3++ will bring the iterator towards left now (originally towards the start of array)

    cout<<v3.back(); // Points towards the last element


    // PRINTING VECTORS
    // Using index
    for(int i = 0; i < v3.size(); i++)
        cout<<v3[i];

    // Using iterators (length declaration)    
    for(vector<int>::iterator it4 = v3.begin(); it4!= v3.end(); it4++){
        cout<<*(it4);
    }

    // Using iterators( using short declaration from using "auto" keyword)
    // auto means iterator on the data
    for(auto it = v3.begin(); it != v3.end(); it++){
        cout<<*(it);
    }

    for(auto it:v1) // it on v1;
        cout<<it;
    
    //DELETION IN VECTORS
    vector<int> v = {1,2,3,4,5,6};
    v.erase(v.begin() + 1); // {1,3,4,5,6}

    // {0,1,2,3,4,5} ==> {0,1,4,5};
    v.erase(v.begin() + 2, v.begin() + 4); // It will delete from index 2 to 3 and v.begin() + 4 (4th) is excluded.

    // INSERTING INTO VECTOR
    vector<int> v = {1,2,3,4,5};
    //v.begin() actually points at 0th index
    v.insert(v.begin(), 00); // 0 1 2 3 4 5 --> adds at 0th index
    v.insert(v.begin() + 1, 12); // 0 12 1 2 3 4 5  --> adds at 1st index
    v.insert(v.begin() + 3, 2, 9); // 0 12 1 9 9 2 3 4 5  --> adds 2 instance of 9 at 3rd index

    vector<int> toBeInserted(3,40); // {40,40,40}
    v.insert(v.end(), toBeInserted.begin(), toBeInserted.end()); // 0 12 1 9 9 2 3 4 5 40 40 40 
    // v.end() basically points after the last index.
    // if {1,2,3} is vector, cout<<*(v.end() - 1) will print 3 and cout<<*(v.end()) will print 0(depending on compiler which value it takes).

    v.pop_back(); // Removed last element
    v1.swap(v3); // Swaps vector v1 with vector v3
    v1.clear(); // Erases everything
    v1.empty(); // If its having something. Returns boolean



}
int main(){
    explainVector();
    return 0;
}