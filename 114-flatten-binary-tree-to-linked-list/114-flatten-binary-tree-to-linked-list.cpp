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
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr){
            TreeNode *currLeft = curr->left;
            while(currLeft && currLeft->right){
                currLeft = currLeft->right;
            }
            if(currLeft)
                currLeft->right = curr->right;
            if(curr->left)
                curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
        }
        return;
    }
};