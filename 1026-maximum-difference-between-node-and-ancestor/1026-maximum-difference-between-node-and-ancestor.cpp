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
    int ans = 0;
    pair<int,int> helper(TreeNode *root){
        if(!root) return {-1e9,1e9};
        if(!root->left && !root->right) return {root->val, root->val};
        pair<int,int>Left = helper(root->left);
        pair<int,int>Right = helper(root->right);
        int minValue = min(Left.second, Right.second);
        int maxValue = max(Left.first, Right.first);
        ans = max(ans, max(abs(root->val - minValue), abs(root->val - maxValue)));
        return {max(maxValue, root->val), min(minValue, root->val)};
        
    }
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};