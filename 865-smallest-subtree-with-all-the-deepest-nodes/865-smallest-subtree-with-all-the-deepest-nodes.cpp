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
    int maxDepth(TreeNode *root){
        if(!root) return NULL;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    TreeNode* helper(TreeNode *root, int maxDepth){
        if(!root) return NULL;
        if(maxDepth == 1) return root;
        TreeNode *Left = helper(root->left, maxDepth-1);
        TreeNode *Right = helper(root->right, maxDepth-1);
        if(Left && Right) return root;
        else if(!Left) return Right;
        else return Left;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxD = maxDepth(root);
        return helper(root, maxD);
    }
};