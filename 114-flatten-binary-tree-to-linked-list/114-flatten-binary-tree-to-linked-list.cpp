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
        TreeNode *tempRight, *tempLeft;
        while(root){
            tempRight = root->right;
            tempLeft = root->left;
            while(tempLeft && tempLeft->right){
                tempLeft = tempLeft->right;
            }
            if(tempLeft)
                tempLeft->right = tempRight;
            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};