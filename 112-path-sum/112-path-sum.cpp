class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right)
        {
            if(root->val == targetSum)
                return true;
            return false;
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};