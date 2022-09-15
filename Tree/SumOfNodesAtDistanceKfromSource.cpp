#include<bits/stdc++.h>
using namespace std;
/*
Problem Link: https://practice.geeksforgeeks.org/contest/interview-series-66/problems/#

Statement:
Chhota Bheem wants to eat the maximum number of ladoos in Dholakpur on 
Independence Day. The houses in Dholakpur are arranged in the form of a binary tree 
and have ladoos same as their house number. Chhota Bheem is standing at his 
home initially.

Find the maximum ladoos he can eat if he can go to houses within a maximum distance 
kfrom his house. The number of ladoos at his home should also be included in the 
sum. 
Note: Every house have distinct ladoos in it. 

*/
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data  = data;
        left = right = NULL;
    }
};

Node *homeAddress;

void generateParentMapping(Node *root,unordered_map<Node*, Node*> &parent_map, int home){

    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node *cur_node = q.front();
        q.pop();
        if(cur_node->data == home)  homeAddress = cur_node;
        
        if(cur_node->left){
            parent_map[cur_node->left] = cur_node;
            q.push(cur_node->left);
        }
        if(cur_node->right){
            parent_map[cur_node->right] = cur_node;
            q.push(cur_node->right);
        }
    }
}

int ladoos(Node* root, int home, int k){
    // Your code goes here

    unordered_map<Node*, Node*> parent_map;

    generateParentMapping(root,parent_map,home);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(homeAddress);
    visited[homeAddress] = true;
    int cur_distance  = 0;

    int laddosCount = 0;
    while(!q.empty()){
        int total_nodes_in_level = q.size();
        if(cur_distance > k)
            break;
        cur_distance++;

        for(int i = 0; i < total_nodes_in_level; i++){
            // Traversing all levels: 1) Left 2) Right 3) Parent
            Node *cur_node = q.front();
            //cout<<"cur_node->data = "<<cur_node->data<<endl;
            laddosCount+=(cur_node->data);
            q.pop();
            
            // If left level of nodes exists
            if(cur_node->left && visited[cur_node->left] == false){
                q.push(cur_node->left);
                visited[cur_node->left] = true;
            }

            // If right levels of nodes exits
            if(cur_node->right && visited[cur_node->right] == false){
                q.push(cur_node->right);
                visited[cur_node->right] = true;
            }
            
            // If parent level of nodes exist
            // If parent exists && visited
            if(parent_map[cur_node] && visited[parent_map[cur_node]]== false){
                q.push(parent_map[cur_node]);
                visited[parent_map[cur_node]] = true;
            }
        }
    }    
    return laddosCount;

}

int main(){
   
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);

    /*
        10
    20      30
        40      50
                    60
    */

   cout<<ladoos(root, 30,1);


    return 0;
}