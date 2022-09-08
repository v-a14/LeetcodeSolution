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
#define ll long long 
class Solution {
public:
    bool helper(TreeNode *root, ll minVal, ll maxVal){
        if(!root) return true;
        if(root->val < minVal || root->val > maxVal) return false;
        bool Left = helper(root->left, minVal, (ll)root->val-1);
        if(!Left) return false;
        bool Right = helper(root->right, (ll)root->val+1, maxVal);
        if(!Right) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};