#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
- Priority queue by default keeps largest element in the first
- It basically implements a tree inside it.
- STL Priority Queue is the implementation of Heap Data Structure.
- We can have smallest/largest element as a priority.
- We cant use iterators to traverse. We only have to use while(!pq.empty()) to access the top
*/
void explainPriorityQueue(){ // push(),pop() in log(n), top-> O(1)
    
    priority_queue<int> pq; // By default it will be max priority queue called MAX HEAP
    pq.push(1); // 1
    pq.push(10); // 10 1
    pq.push(5); // 10 5 1 

    pq.top(); // prints 10
    pq.pop(); // 5 1

    // Size swap and empty functions works same as others

    // Priority Queue with small element as preference

    priority_queue<int , vector<int> , greater<int>> pq2; // MIN HEAP
    /**
     * ‘int’ is the type of elements you want to store in the priority queue. 
            In this case, it’s an integer. 
            You can replace int with any other data type you need.
     * ‘vector<int>’ is the type of internal container used to store these elements. 
            std::priority_queue is not a container in itself but a container adopter.
            It wraps other containers. 
            In this example, we’re using a vector, but you could choose a different container that supports front(), push_back(), and pop_back() methods. 
     * ‘greater<int>‘ is a custom comparison function. 
            This determines how the elements are ordered within the priority queue. 
            In this specific example, greater<int> sets up a min-heap. 
            It means that the smallest element will be at the top of the queue.
     */

    // Creating a priority queue of map<int,int> with smaller element on priority (Called MIN HEAP)
    priority_queue< map<int, int> , vector< map<int, int>> , greater< map<int, int> > > pq3;
    map<int, int> mp1;
    mp1[2] = 0;
    mp1[10] = 124;
    mp1[13] = 12;
    mp1[-1] = 1;

    pq3.push(mp1);

    while(!pq3.empty()){
        map<int,int> mp = pq3.top(); // We have to explicitly store the top in a variable and auto mp wont work
        
        /* Outputs:
            -1 1  
            2 0   
            10 124
            13 12
        */
        for(auto it: mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        pq3.pop(); // DELETING: O(LogN) operation
    }

     // IMP Info:
     /**
      * priority_queue in C++ does not support direct iteration using a standard range-based for loop
      * Thus we have to iterate using while() loop only
      */

    // Priority Queue of Pairs
    priority_queue<pair<int, int>> pqq;  // Max-Heap (Highest key first)

    pqq.push({12, 1});
    pqq.push({11, 33});
    pqq.push({4, 2});

    while (!pqq.empty()) {
        pair<int, int> top = pqq.top();
        cout << top.first << " => " << top.second << endl;
        pqq.pop();
    }

}

int main(){
    explainPriorityQueue();
    return 0;
}
