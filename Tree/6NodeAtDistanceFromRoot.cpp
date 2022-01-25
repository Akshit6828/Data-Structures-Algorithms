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

void printNodeAtDistance(Node *node, int distance){ // TC: O(N) , SC; O(h)
// TC: O(N) as in worst case we need to go to every node. For best case: O(1) when root  = NULL
//SC: O(H) as in worst case nodes = height of tree will be there in stack call.

    if(node == NULL && distance>=0){ // Case: If no nodes is present at that distance and we reach leaf node.
    cout<<"No nodes at desired distance\n";
    // This condition is being called O(n) times as it will check for N times.
    return;
    }

    if(node == NULL)  // Case: If root node is NULL.
        return;

    if(distance == 0)// Case: If we have reached at desired distance
        cout<<(node->key)<<" ";
    else{ // Getting 1 step closer
        printNodeAtDistance(node->left, distance - 1); 
        printNodeAtDistance(node->right, distance -1);
    }

}
int main(){
    int distance;
    cin>>distance;
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(50);
    printNodeAtDistance(root,distance);
    return 0;
}