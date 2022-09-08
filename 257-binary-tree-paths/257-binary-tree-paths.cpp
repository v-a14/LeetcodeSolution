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
    void helper(TreeNode *root, string curr, vector<string>&ans){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            string temp = curr + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        string temp = curr + to_string(root->val) + "->";
        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr = "";
        helper(root, curr, ans);
        return ans;
    }
};