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
    string ans = "{";
    void helper(TreeNode *root, string temp){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            temp += (char)(root->val + 'a');
            reverse(temp.begin(), temp.end());
            ans = min(ans, temp);
            return;
        }
        temp += (char)(root->val + 'a');
        helper(root->left, temp);
        helper(root->right, temp);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp;
        helper(root, temp);
        return ans;
    }
};