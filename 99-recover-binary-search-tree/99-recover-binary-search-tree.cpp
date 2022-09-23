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
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->val < prev->val){
            if(first==NULL){
                middle = root;
                first = prev;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last != NULL){
            swap(first->val, last->val);
        }else{
            swap(first->val, middle->val);
        }
        return;
    }
};