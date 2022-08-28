#include<bits/stdc++.h>

// Problem 1: 
// Start deleting the roots and give the order such that, they would be deleted.
// Parent should be the last one to be deleted and the parent whose node has been deleted would be having the more priority than the other parents.


struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key  = key;
        left = right = NULL;
    }
};

// Follow ups : If you wana make sure, if the element to be deleted pops out the last
std::vector<int> DeleteNodeFromLeafToParent(Node *root, std:: vector<int> &orderedNodes){
    if(root == NULL)
        return order;
    deleteFromNode(root->left, order);
    deleteFromNode(root->right, order);
    orderedNodes.emplace_back(root->key);
    if(root -> left!=NULL)
        root->left = NULL;
    if(root -> right != NULL)
        root->right = NULL;
        return order;
}
    

int main(){
   
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);
    vector<int> ans;
    DeleteNodeFromLeafToParent(root, ans);

    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}
/*
             10
        20          30
                40      50
                            60
*/