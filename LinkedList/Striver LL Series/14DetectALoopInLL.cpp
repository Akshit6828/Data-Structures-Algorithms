#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    
    Node(int n){
        data = n;
        next = NULL;
    }
};

/*
Intution for fast and slow pointers:

- If there would be cycle, then for sure "FAST" and "SLOW" will always meet inside the cycle
Why?
- Lets say they have distance "d".
- After each iteration fast moves 2 steps towards slow, and slow moves 1 step away from fast.
- So now the distance between them would be "d-1";
...
...
...
After some iterations, these "d" will be 0 and both fast and slow will meet at a common node.
*/

bool hasCycle(Node *head) {
    bool cycleFound = false;
    Node* slow = head;
    Node* fast = head;

   while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycleFound = true;
            break;
        }
    }
    return cycleFound;
}

int main(){
    // No main since we cannot make a Linked List by self having a cycle.
    // Or it will take much time to connect pointers again
}