#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *previous;
    Node *next;

    Node(int data){
        this->data = data;
        previous = next =  NULL;
    }
};

Node* reverseDoubleLinkedList(Node *head){
    if(head == NULL || head->next == NULL) // There are 0 or 1 node;
        return head;
    Node *tempBackNode = NULL;
    while(head!=NULL){
        tempBackNode = head->previous;
        head->previous = head->next;
        head->next = tempBackNode;
        head = head->previous;
    }
    return tempBackNode->previous;
}

int main(){

    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);

    head->next = node1;
    node1->previous = head;
    node1->next = node2;
    node2->previous = node1;

    Node *newHead = reverseDoubleLinkedList(head);
    cout<<"NEW HEAD  = "<<newHead->data<<endl;
    while(newHead!=NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    
    return 0;
}