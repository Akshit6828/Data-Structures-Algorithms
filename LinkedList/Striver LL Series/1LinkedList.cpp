#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int n){
        data = n;
        next = NULL;
    }

    Node(int n, Node* ptr){
        data = n;
        next = ptr;
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

int lengthOfLL(Node *head){
    Node *current = head;
    int len = 0;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

int main(){
    vector<int> arr = {12,4,6,2};
    Node *head = convertArray2LL(arr);
    printLL(head);
    cout<<lengthOfLL(head)<<endl;
    return 0;
}