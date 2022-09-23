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
    bool helper(TreeNode *root, long long minVal, long long maxVal){
        if(!root) return true;
        if(root->val < minVal || root->val > maxVal) return false;
        bool left =  helper(root->left, minVal, (long long)root->val-1);
        if(!left) return left;
        bool right = helper(root->right, (long long)root->val+1, maxVal);
        if(!right) return right;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};