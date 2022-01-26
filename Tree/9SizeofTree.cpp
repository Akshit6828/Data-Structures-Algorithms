#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key  = key;
        left = right = NULL;
    }
};


// Concept of using default argument
int sizeOfTree(Node *root, int ans = 0){
    if(root == NULL)
        ans+=0;
    else
    ans = ans+ 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
    return ans;
}


    

int main(){
   
    Node *root = NULL;
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);

    cout<<sizeOfTree(root); //Default Argument passed is 0. So we need not to specify it.

    return 0;
}