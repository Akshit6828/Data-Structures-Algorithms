#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node*  insertAtKthPos(Node *head, int pos, int val){
    Node *newNode = new Node(val);
    if(pos == 1){
        newNode->next = head;
        return newNode;
    }
    Node *current = head;
    
    for(int i = 1; i<= pos-2; i++){
        current = current->next;            
    }
    if(current==NULL)
            return head;   

    
    newNode->next = current->next;
    current->next = newNode;
    return head;

}
int main(){
    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    head->next = node1;
    node1->next = node2;

    cout<<"LL Before insertion\n";
    Node *temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\nEnter pos and val of new Node to be inserted\n";
    int pos, val;
    cin>>pos>>val;
    Node *newHead = insertAtKthPos(head, pos, val);
    cout<<"LL After insertion\n";
   while (newHead!=NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    return 0;
}