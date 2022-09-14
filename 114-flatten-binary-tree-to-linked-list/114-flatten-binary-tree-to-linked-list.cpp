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
    void flatten(TreeNode* root) {
        TreeNode *Left, *Right;
        while(root){
            TreeNode *Left = root->left;
            while(Left && Left->right){
                Left = Left->right;
            }
            if(Left)
                Left->right = root->right;
            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
        return;
    }
};