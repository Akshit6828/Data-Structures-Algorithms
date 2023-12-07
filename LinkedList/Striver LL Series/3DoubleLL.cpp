#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    
    Node(int n){
        data = n;
        next = NULL;
        back = NULL;
    }

    Node(int n, Node* next1 , Node* back1){
        data = n;
        next = next1;
        back = back1;
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
Node* convertArray2DoublyLL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


int main(){
    vector<int> arr = {2,4,7,5,6};
    Node* head = convertArray2DoublyLL(arr);
    printLL(head);
    return 0;
}