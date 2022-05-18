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


void printLeftView(Node * root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int levelLen = q.size(); // only compute size of queue.
        
        for(int i= 0;i<levelLen; i++){

            Node *currentNode  = q.front();
            q.pop();
            if(i == 0)
                cout<<(currentNode->key)<<" ";           
            if(currentNode->left!=NULL)
                q.push(currentNode->left);
            if(currentNode->right!=NULL)
                q.push(currentNode->right);
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
    printLeftView(root);

    return 0;
}
/*
            10
        20      30
    40              50
                        60
*/