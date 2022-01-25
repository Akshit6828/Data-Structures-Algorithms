#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *leftChild;
    Node *rightChild;
    
    Node(int key){
        this->key = key;
        leftChild = rightChild = NULL;
    }

};

void printPreorder(Node *node){// TC: O(n). SC: O(h) where h = height of tree(no of nodes on longest path from root to leaf)
// TC: O(N) because if its internal node, we just print it. If leaf, we print it and recursively call nullLeft and nullRight which again is constant work as it wont have further calls.
// So basically we are doing constant amount of work for every node so, its O(N) time complexity

// SC: O(h+1) == O(h) {h+1 because it will have NULL call too which wont call any recursive call ahead}
    if(node!=NULL){
        cout<<(node->key)<<" ";
        printPreorder(node->leftChild);
        printPreorder(node->rightChild);
    }    
}
int main(){
    Node *root  = new Node(10);
    root->leftChild = new Node(20);
    root->rightChild = new Node(30);
    root->rightChild->leftChild = new Node(40);
    root->rightChild->rightChild = new Node(50);
    printPreorder(root);
    return 0;
}