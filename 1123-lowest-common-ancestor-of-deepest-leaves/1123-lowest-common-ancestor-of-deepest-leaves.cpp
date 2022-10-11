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
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    TreeNode *getLCA(TreeNode *root, int level){
        if(!root) return NULL;
        if(level == 1) return root;
        TreeNode *left = getLCA(root->left, level-1);
        TreeNode *right = getLCA(root->right, level-1);
        if(left && right) return root;
        else if(!left) return right;
        else return left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return getLCA(root, maxDepth(root));
    }
};