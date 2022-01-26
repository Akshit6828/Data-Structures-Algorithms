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



void printLevelOrder(Node *root, vector<vector<int>> &orderedNodes ){

     if(root==NULL)
        return;
    queue<Node*> nodeQueue;
    
    nodeQueue.push(root);

    //orderedNodes[0].push_back(root->key);

    int index = 1;

    while(!nodeQueue.empty()){
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        cout<<(currentNode->key)<<" ";
        //orderedNodes[index].push_back(currentNode->key);
        

        if(currentNode->left!=NULL){
            nodeQueue.push(currentNode->left);
            //orderedNodes[index].push_back(currentNode->left->key);
        }
        if(currentNode->right!=NULL){
            nodeQueue.push(currentNode->right);
            //orderedNodes[index].push_back(currentNode->right->key);
        }
        //index++;
    }
    
        
}

int main(){
   
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);
    
    vector<vector<int>> levelOrdereNodes;
    printLevelOrder(root, levelOrdereNodes);
    /*for(auto &level: levelOrdereNodes){
            for(auto &node: level)
                cout<<node<<" ";
            cout<<endl;
    }*/
        
    return 0;
}