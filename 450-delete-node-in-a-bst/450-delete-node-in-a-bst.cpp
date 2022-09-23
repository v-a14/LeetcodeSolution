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
    TreeNode *helper(TreeNode *curr){
        // if left or right is null, simply return that is not null 
        if(!curr->left) return curr->right;
        else if(!curr->right) return curr->left;
        
        TreeNode *currLeft = curr->left;
        while(currLeft->right) currLeft = currLeft->right;
        currLeft->right = curr->right;
        return curr->left;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode *curr = root;
        while(curr){
            if(curr->val > key){
                if(curr->left && curr->left->val == key){
                    curr->left = helper(curr->left);
                }else{
                    curr = curr->left;
                }
            }else{
                if(curr->right && curr->right->val == key){
                    curr->right = helper(curr->right);
                }else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};