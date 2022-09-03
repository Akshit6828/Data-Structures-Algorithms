/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

Approach/Idea:

Try traversing the whole tree and keep a variable max_till_now which keep track of the Maximum Value of Element from Root till Current Node (current path maximum).
If we find the value of current node >= max_till_now, just increment the goodNodesCount.
*/

void findGreaterNodes(TreeNode* root, int &goodNodesCount, int max_till_now){
        if(root == NULL)
            return;
        
        if(root->val >= max_till_now){ // If current val > max_till_now. Common you've got a new greater to maintain. Update max_till_now and increment goodNodesCount.
            goodNodesCount++;
            max_till_now = max(max_till_now, root->val);
        }
        
		// Slight Leaf Node Optimization. (You can delete this condition too)
        if(root->left == NULL && root->right == NULL) // Optimize code via avoiding calling 2 more recursive calls with root = NULL. So better check here only and return.
             return;

        if(root->left != NULL) // If there is a node on left..lets explore it bro
            findGreaterNodes(root->left, goodNodesCount,max_till_now);
    
        if(root->right != NULL)// If there is a node on right..lets explore it bro
            findGreaterNodes(root->right, goodNodesCount,max_till_now);
        
    }
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 0, max_till_now =INT_MIN;
        findGreaterNodes(root,goodNodesCount, max_till_now);
        return goodNodesCount;
    }
};