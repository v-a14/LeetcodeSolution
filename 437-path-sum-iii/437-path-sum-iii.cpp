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
    void helperSum(TreeNode *root, ll currSum, ll targetSum, ll &count){
        if(!root) return;
        currSum += root->val;
        if(currSum == targetSum) count++;
        helperSum(root->left, currSum, targetSum, count);
        helperSum(root->right, currSum, targetSum, count);
        currSum -= root->val;
        return;
    }
    void inorder(TreeNode *root, ll &count, ll targetSum){
        if(!root) return;
        ll temp = 0;
        helperSum(root, 0, targetSum, temp);
        count += temp;
        inorder(root->left, count, targetSum);
        inorder(root->right, count, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        ll count = 0;
        inorder(root, count, targetSum);
        return (int)count;
    }
};