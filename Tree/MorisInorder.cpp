#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node *left, *right;
    int val;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

void MorrisInorder(Node *root, vector<int> &inorder){
    Node *cur = root;// storing root so that we need not to modify it
    
    while(cur!=NULL){
        
        // If left doesnt exist
        if(cur->left == NULL){
            inorder.emplace_back(cur->val);
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{ // If left occurs: Go to the left subtree and go to the right-most guy. ie find the inorder predesor of the tree.

            Node *prev = cur->left; // we move left

            // while we have the right of this left subtree AND
            // This right should not be pointing to towards the current node. (Cur).
            // Because if it pointed towards the cur, it is already a visited and the thread has already been made.
            
            while(prev->right && prev->right !=cur){ 
                prev = prev->right;
            }

            // Now following case arrives
            // Case 1: If prev->right = NULL: Then make a thread to current node
            // Case2: If prev-right = cur; // Remov
            if(prev->right == NULL){
                prev->right = cur; // Establish link
                cur = cur->left; // Now proceed
            }
            else{
                prev ->right = NULL; // Break the thread after we have done.
                cout<<cur->val <<" ";
                inorder.push_back(cur->val);
                cur = cur->right; // Procedding to the thread
                
               
            }
        }
    }
}


void MorrisInorder(Node *root, vector<int> &inorder){
    Node *cur = root;// storing root so that we need not to modify it
    
    while(cur!=NULL){
        
        // If left doesnt exist
        if(cur->left == NULL){
            inorder.emplace_back(cur->val);
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{ // If left occurs: Go to the left subtree and go to the right-most guy. ie find the inorder predesor of the tree.

            Node *prev = cur->left; // we move left

            // while we have the right of this left subtree AND
            // This right should not be pointing to towards the current node. (Cur).
            // Because if it pointed towards the cur, it is already a visited and the thread has already been made.
            
            while(prev->right && prev->right !=cur){ 
                prev = prev->right;
            }

            // Now following case arrives
            // Case 1: If prev->right = NULL: Then make a thread to current node
            // Case2: If prev-right = cur; // Remov
            if(prev->right == NULL){
                prev->right = cur; // Establish link
                cur = cur->left; // Now proceed
            }
            else{
                prev ->right = NULL; // Break the thread after we have done.
                cout<<cur->val <<" ";
                inorder.push_back(cur->val);
                cur = cur->right; // Procedding to the thread
                
               
            }
        }
    }
}


void inOrder(Node *root){
    if(root == NULL)
    return;
    inOrder(root->left);
    cout<<root->val<<" -> ";
    inOrder(root->right);
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);
    
    vector<int> inorder;
    Node *dummyroot= root;
    //inOrder(dummyroot);
    cout<<endl;
    MorrisInorder(root, inorder);

    cout<<endl;
    for(auto i: inorder)
        cout<<i<<" - ";

    return 0;
}
/*
            10
        20      30
              40   50
                      60
*/