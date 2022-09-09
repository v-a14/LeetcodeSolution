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
    int findDepth(TreeNode *root){
        if(!root) return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    TreeNode *lca(TreeNode *root, int level){
        if(!root) return NULL;
        if(level == 1){
            return root;
        }
        TreeNode *Left = lca(root->left, level-1);
        TreeNode *Right = lca(root->right, level-1);
        if(Left && Right) return root;
        else if(!Left) return Right;
        else if(!Right) return Left;
        else return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = findDepth(root);
        return lca(root, depth);
    }
};