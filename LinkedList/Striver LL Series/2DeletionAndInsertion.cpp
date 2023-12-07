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

Node* deleteHead(Node* head){
    if( head == NULL){ // If the linked list is empty
        return NULL;
    }
    Node* temp = head; // Lets store head's reference in another variable so that we can use delete on that variable
    head = head->next;
    delete temp; // Deletes the location to which this pointer variable points
    return head;

}

Node* deleteTail(Node* head){
    if( head == NULL || head->next == NULL){ // If the linked list is empty or the only 1 element is present where head of LL = tail of LL
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    // After this loop ends we are standing at the 2nd last node
    
    delete temp->next; // deletes the next element from the temp
    temp->next = NULL;
}

// 12 3 4 5 8 9 ( k = 4(1 based indexing) ie. 5)
Node* removeNoteAtKthIndex(Node* head , int k){
    if(head == NULL)
        return NULL;
    
    if(k == 1){ // Its similar to removing head
        Node* temp = head; // Lets store head's reference in another variable so that we can use delete on that variable
        head = head->next;
        delete temp; // Deleting that reference
        return head;
    }
    else{ // Now we are deleting intermediate notes
        Node * temp = head; // We take temp just so that we can delete the node when temp reach at kth pos
        Node *prev = NULL;
        int count = 0;
        while(temp != NULL){ // Better to iterate using temp!= NULL because there might be case where k> length of LinkedList
            count++;
            if(count == k){ // We have reached the kth node which has to be deleted. "temp" is at current node and prev is behind that node
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
}

// 12 3 4 5 8 9 ( k = 4(1 based indexing) ie. 5)
Node* removeNodeWithKValue(Node* head , int val){
    if(head == NULL)
        return NULL;
    if(head->data == val){
        Node * temp = head;
        head = head->next;
        delete temp;
        return head;
    } else{
        Node *temp = head;
        Node* prev = NULL;
        while(temp!= NULL){
            prev = temp;
            temp = temp->next;
            if(temp->data == val){
                prev->next = prev->next->next;
                delete temp;
                break;
            }
        }
        return head;
    }
}

// ----------- Inserting Nodes

Node* insertAtHead(Node *head, int val){
    Node* newHead = new Node(val);
    newHead->next = head;
    return newHead;
}

Node* insertAtEnd(Node*head, int val){

    if(head == NULL){
        Node *newNode = new Node(val);
        return newNode;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertAtKthPosition(Node* head, int val,  int k){
    if(head == NULL){
        if(k == 1){ // Explicitly checking if K == 1 since if LL is empty and any other value except 1 would be invalid
            Node *newNode = new Node(val);
            return newNode;
        } else{
            cout<<"Invalid value of K since LinkedList is empty and only can be inserted at 1.";
        }
    } else{
        Node *temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            if(count == k-1){
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

        return head;
    }
}

int main(){
    vector<int> arr = {12, 4, 33, 22, 23};
    Node* head = convertArray2LL(arr);
    printLL(head);
    head = insertAtHead(head, 11);
    printLL(head);
    head = insertAtEnd(head, 24);
    printLL(head);
    head = insertAtKthPosition(head, 35, 4);
    printLL(head);
    return 0;
}