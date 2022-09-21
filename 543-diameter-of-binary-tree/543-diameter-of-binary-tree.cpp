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
    pair<int,int> helper(TreeNode *root){
        if(!root) return {0,0};
        pair<int,int>left = helper(root->left);
        pair<int,int>right = helper(root->right);
        int ans = max(max(left.second, right.second), left.first+right.first+1);
        return {max(left.first, right.first) + 1, ans};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second-1;
    }
};