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
    void Traverse(TreeNode *root, vector<int>&inorder){
        if(!root) return;
        Traverse(root->left, inorder);
        inorder.push_back(root->val);
        Traverse(root->right, inorder);
        return;
    }
    void againTraverse(TreeNode *root, vector<int>&inorder, int &idx){
        if(!root) return;
        againTraverse(root->left, inorder, idx);
        root->val = inorder[idx++];
        againTraverse(root->right, inorder, idx);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        Traverse(root, inorder);
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        againTraverse(root, inorder, idx);
    }
};