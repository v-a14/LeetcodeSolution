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
    void helper(TreeNode *root, set<int>&s, vector<TreeNode*> &ans){
        if(!root) return;
        if(s.find(root->val) != s.end()){
            if(root->left && s.find(root->left->val)==s.end()) ans.push_back(root->left);
            if(root->right && s.find(root->right->val)==s.end()) ans.push_back(root->right);
        }
        helper(root->left, s, ans);
        helper(root->right, s, ans);
        if(root->left && s.find(root->left->val) != s.end()){
            root->left = NULL;
        }
        if(root->right && s.find(root->right->val) != s.end()){
            root->right = NULL;
        }
        return;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        set<int>s;
        for(auto it:to_delete){
            s.insert(it);
        }
        if(s.find(root->val)==s.end()) ans.push_back(root);
        helper(root, s, ans);
        return ans;
    }
};