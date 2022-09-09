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
    bool dfs(TreeNode *root, vector<int>&voyage, int &idx, vector<int>&ans){
        if(!root) return true;
        if(root->val != voyage[idx++]) return false;
        bool Left = false, Right = false;
        if(root->left && root->left->val != voyage[idx]){
            ans.push_back(root->val);
            Left = dfs(root->right, voyage, idx, ans);
            if(!Left) return Left;
            Right = dfs(root->left, voyage, idx, ans);
            if(!Right) return Right;
            return true;
        }else{
            Left = dfs(root->left, voyage, idx, ans);
            if(!Left) return Left;
            Right = dfs(root->right, voyage, idx, ans);
            if(!Right) return Right;
            return true;
        }
        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        int idx = 0;
        bool flag = dfs(root, voyage, idx, ans);
        if(flag) return ans;
        return {-1};
    }
};