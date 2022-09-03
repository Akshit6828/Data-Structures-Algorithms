/*
Problem:
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void BFS_Tree(TreeNode *root, vector<double>& averages){
        if(root == NULL)
            return;
        
        queue<TreeNode*> q;
        q.push(root);   
        while(!q.empty()){
            TreeNode* node = q.front();
            int level_len = q.size();
            double level_sum = 0;
            
            for(int  i = 0; i< level_len; i++){
                TreeNode * cur_node = q.front();
                q.pop();
                level_sum += cur_node->val;
                if(cur_node->left)
                    q.push(cur_node->left);
                if(cur_node->right)
                    q.push(cur_node->right);
                
            }
            
            double average = level_sum/level_len;
            averages.push_back(average);
            
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        BFS_Tree(root,averages);
        return averages;
        
    }
};