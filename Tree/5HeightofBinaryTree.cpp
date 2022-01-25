#include<bits/stdc++.h>
using namespace std;

/* Height of a Binary Tree:
    = MAXIMUM Number of nodes from root to leaf.
    = (Number of EDGES +1) on Longest Path
*/
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int currentNodeValue){
        data = currentNodeValue;
        left = right = NULL;
    }
};

int heightOfTree(Node *currentNode){ // TC: O(N) , SC:O(h)
// TC: O(N) as we are doing constant work at each node (comparing and adding 1)
//SC: O(h) because max calls in stack will be O(h+1) == O(h). {h+1 for NULL Call too. }

    if(currentNode == NULL)
        return 0;
    else 
    return max(heightOfTree(currentNode->left), heightOfTree(currentNode->right)) + 1; // +1 as we have processed one level. So adding count of this level.

}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);    
    root->right = new Node(30);    
    root->right->left = new Node(40);    
    root->right->right = new Node(50);
    root->right->right->right = new Node(50);
    cout<<heightOfTree(root);
    return 0;
}