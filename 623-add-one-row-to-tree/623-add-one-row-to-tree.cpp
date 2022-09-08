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
    void helper(TreeNode *root, int depth, int val){
        if(!root) return;
        if(depth == 2){
            // create left nodes;
            TreeNode *newNode = new TreeNode(val);
            TreeNode *tempLeft = root->left;
            root->left = newNode;
            newNode->left = tempLeft;
            
            // create rightNodes
            newNode = new TreeNode(val);
            TreeNode *tempRight = root->right;
            root->right = newNode;
            newNode->right = tempRight;
        }
        helper(root->left, depth-1, val);
        helper(root->right, depth-1, val);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        helper(root, depth, val);
        return root;
    }
};