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

// Helper functions
void printLL(Node* head){
    Node* current = head;
    while(current!= NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}
Node* convertArray2LL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]); // Creating a new node
        mover->next = temp;
        mover = temp;
    }
    return head;
}

/*

1) If LL is odd, it has 1 middle. (n/2) + 1 index.
2) If LL is even, it has 2 middle and so we will return 2nd middle ie.(n/2) + 1.

So middle of LL = (n/2) + 1;

Intution for fast and slow pointers:

- If person1(slow) moves at a speed d and covers distance x.
So
person2(Fast) moves at speed (2*d), so it will cover distance 2x. where 2x  = last node of linkedlist.
So person1 will always be standing in the middle of the linked list.

Important points to note:
1) if n == ODD, then FAST WILL BE AT "LAST NODE" and SLOW WILL BE AT "MIDDLE NODE".
2) if n == EVEN, then FAST will be at NULL(After end) and SLOW WILL BE AT "MIDDLE NODE".
The "FAST" will never be reaching last node in case of even length.

*/

Node* findMiddleOfLinkedListUsingTortoiseAndHare(Node* head){
    Node* slow = head;
    Node* fast = head;

    //Choosing the while condition
    /*
    We know that either my fast is at the last node(for odd length) or its at the null(for even length).
    So for all other fast in the mid way,fast will not be NULL && fast->next would also not be null.
    Because if we reach a condition where either fast = NULL or fast->next is null, it means we have reached End.
    */
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // As soon as loop ends, fast is pointing towards either last node(for odd length) or NULL(for even length). But for sure our slow is at middle.
    // So returning slow and we confirm slow will always be at 2nd node.
    return slow;
}
int main(){
    vector<int> arr = {12, 4, 33, 22, 23, 66 };
    Node* head = convertArray2LL(arr);
    printLL(head);
    Node* middleNode = findMiddleOfLinkedListUsingTortoiseAndHare(head);
    cout<<middleNode->data;
    return 0;
}