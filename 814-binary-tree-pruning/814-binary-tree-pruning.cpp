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
    bool helper(TreeNode *root){
        if(!root) return false;
        if(!root->left && !root->right) return root->val == 1; 
        bool left = helper(root->left);
        if(left == false) root->left = NULL;
        bool right = helper(root->right);
        if(right == false) root->right = NULL;
        return left || right || (root->val == 1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = helper(root);
        if(!flag) return NULL;
        return root;    
    }
};