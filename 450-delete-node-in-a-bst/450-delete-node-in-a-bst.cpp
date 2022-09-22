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
        TreeNode *Node = root->left;
        TreeNode *ansNode = root->left;
        TreeNode *temp = root->right;
        while(Node->right) Node = Node->right;
        Node->right = temp;
        return ansNode;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode *prev = NULL, *curr = root;
        if(root->val == key) return helper(root);
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