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
    TreeNode *prev = NULL, *first = NULL, *middle = NULL, *last = NULL;
    void helper(TreeNode *root){
        if(!root) return;
        helper(root->left);
        if(prev!=NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(last!=NULL){
            swap(first->val, last->val);
        }else{
            swap(first->val, middle->val);
        }
        return;
    }
};