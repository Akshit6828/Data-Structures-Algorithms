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

int main(){

    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    head->next = node1;
    node1->previous = head;
    node1->next = node2;
    node2->previous = node1;

    Node *tail;
    cout<<"Iteration from left to right\n";
    while(head!=NULL){
        cout<<(head->data)<<" ";
        tail = head;
        tail->previous = head->previous;
        head = head->next;
       
       // cout<<" Tail now updated to:->"<<tail->data<<" ";
    }
    cout<<endl;

    cout<<"Iteration from right to left\n";
    while(tail!=NULL){
        cout<<(tail->data)<<" ";
        tail = tail->previous;
    }
    
    return 0;
}