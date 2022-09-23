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
    vector<int>helper(TreeNode *root){
        // maximum value, minimum value, sum 
        if(!root) return {INT_MIN, INT_MAX, 0};
        vector<int>left = helper(root->left);
        vector<int>right = helper(root->right);
        int leftMax = left[0];
        int rightMin = right[1];
        int sum = left[2] + right[2];
        if(root->val > leftMax && root->val < rightMin){
            ans = max(ans,  sum + root->val);
            return {max(root->val, right[0]), min(root->val, left[1]), sum + root->val};
        }else
            return {INT_MAX, INT_MIN, 0};
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};