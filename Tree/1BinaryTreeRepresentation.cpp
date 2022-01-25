#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};


int main(){
    Node *root = new Node(10);
    root->left = new Node(20);   
    root->right = new Node(30);
    root->left->left = new Node(40);
    while(root->key){
        cout<<root->key;
        root = root->left;
    }
        
    return 0;
}