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
    int helper(TreeNode *root, int &k){
        if(!root) return -1e9;
        int left = helper(root->left, k);
        if(left!=-1e9) return left;
        k--;
        if(k==0) return root->val;
        int right = helper(root->right, k);
        if(right!=-1e9) return right;
        return -1e9;
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};