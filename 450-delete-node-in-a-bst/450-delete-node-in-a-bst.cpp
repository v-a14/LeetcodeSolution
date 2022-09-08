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
    TreeNode *helper(TreeNode *root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode *RightNode = root->right;
        TreeNode *LeftNode = root->left;
        TreeNode *temp = LeftNode;
        while(temp->right){
            temp = temp->right;
        }
        temp->right = RightNode;
        return LeftNode;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) return helper(root);
        TreeNode *dummy = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                }else{
                    root = root->left;
                }
            }else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};