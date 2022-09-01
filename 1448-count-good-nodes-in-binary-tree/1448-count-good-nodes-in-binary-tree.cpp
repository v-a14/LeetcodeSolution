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
    void helper(TreeNode *root, int &count, int maxV){
        if(!root) return;
        if(root->val>=maxV){
            count++;
        }
        helper(root->left, count, max(maxV, root->val));
        helper(root->right, count, max(maxV, root->val));
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        helper(root, count, -1e9);
        return count;
    }
};