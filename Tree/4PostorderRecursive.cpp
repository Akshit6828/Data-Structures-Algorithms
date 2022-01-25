#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int currentNodeValue){
        data = currentNodeValue;
        left = right = NULL;
    }
};

void printPostorder(Node *currentNode){ // TC: O(n). SC: O(h) where h = height of tree(no of nodes on longest path from root to leaf)
// TC: O(N) because if its internal node, we just print it. If leaf, we print it and recursively call nullLeft and nullRight which again is constant work as it wont have further calls.
// So basically we are doing constant amount of work for every node so, its O(N) time complexity

// SC: O(h+1) == O(h) {h+1 because it will have NULL call too which wont call any recursive call ahead}

    if(currentNode!=NULL){
    printPostorder(currentNode->left);
    printPostorder(currentNode->right);
    cout<<(currentNode->data)<<" ";
    }
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    printPostorder(root);    
    return 0;
}