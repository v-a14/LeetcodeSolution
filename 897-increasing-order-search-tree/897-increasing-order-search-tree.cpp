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
    void inorder(TreeNode *root, TreeNode * &curr){
        if(!root) return;
        inorder(root->left, curr);
        curr->right = root;
        root->left = NULL;
        curr = curr->right;
        inorder(root->right, curr);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        TreeNode *curr = dummy;
        inorder(root, curr);
        return dummy->right;
    }
};