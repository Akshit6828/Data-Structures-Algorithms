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



void printLevelOrderLine(Node *root ){

     if(root==NULL)
        return;
    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    nodeQueue.push(NULL);

    while(nodeQueue.size()>1){
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        
        if(currentNode == NULL){
            cout<<"\n";
            nodeQueue.push(NULL);
        }
        else{

        cout<<(currentNode->key)<<" ";
        
        if(currentNode->left!=NULL)
            nodeQueue.push(currentNode->left);

        if(currentNode->right!=NULL)
            nodeQueue.push(currentNode->right);
        }
    } 
}
    

int main(){
   
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);

    printLevelOrderLine(root);
    return 0;
}