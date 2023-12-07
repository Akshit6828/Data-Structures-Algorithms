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

    Node(int n, Node* next1){
        data = n;
        next = next1;
    }
};

// Helper Functions
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
    AIM: We need to reach the preceding node of the node to be deleted in order to delete the node.
        
    Algo Intuition:
        - We use two pointers, fast and slow, both initially pointing to a dummy node.
        - Move the fast pointer n steps ahead, creating a gap of n nodes between fast and slow.
        - Move both pointers simultaneously until fast reaches the end of the list.
        - At this point, slow is pointing to the node preceding the one to be deleted.  
        - Adjust the pointers to remove the nth node from the end.
        - Free the memory of the deleted node.
        - Return the updated head of the list.

        EDGE CASE: If n(node to be deleted from last) == length of linkedList. In such case, we have to delete the head.
*/

Node* removeNthFromEnd(Node* head, int n) { // TC: O(n), SC:O(1)

        Node* slow = head;
        Node* fast = head;
        
        // Creating a gap between slow and fast, as equal gap of the node preceding the node to be deleted and last node
        for(int i = 0; i<n;i++){
            fast = fast->next;
        }
// At this point after loop executed, gap between fast - slow == gap between lastnode - preceding node to be reached
        
        if(fast == NULL){ // it means fast is already standing next to last node. Since we started fast from head. So 1st node from last is nth(total length) node from beginning.
            Node *temp = head; // Storing cur head in a variable to free it
            head = head->next;
            delete temp; // Deletes Head
            return head;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // now at this point slow will be at the node preceding the node to be deleted
        // So delete the node
        Node* temp = slow->next; // Storing in temp so we can delete
        slow ->next = slow->next->next;
        delete temp;
        return head;
    }
int main(){
    vector<int> arr = {12, 4, 33, 22, 23, 25, 26, 29, 42, 46 ,67};
    Node* head = convertArray2LL(arr);
    printLL(head);
    head = removeNthFromEnd(head, 3);
    printLL(head);
    return 0;
}
