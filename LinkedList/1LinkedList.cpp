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

int main(){ 
    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    head->next = node1;
    node1->next = node2;
    int pos;
    cin>>pos;
    for(int i = 1; i<=pos-2;i++){
        cout<<" - "<<head->data<<endl;
        head = head->next;
    }
    cout<<head->data;
    /*while(head->next!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    while (head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }*/
    
    return 0;
}