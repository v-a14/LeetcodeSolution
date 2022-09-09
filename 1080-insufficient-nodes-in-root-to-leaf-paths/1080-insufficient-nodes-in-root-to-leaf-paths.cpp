class Solution {
public:
    int helper(TreeNode *root, int currSum, int limit){
        if(!root) return -1e9;
        if(!root->left && !root->right){
            currSum += root->val;
            return currSum;
        }
        int left = helper(root->left, currSum+root->val, limit);
        if(left<limit){
            root->left = NULL;
        }
        int right = helper(root->right, currSum+root->val, limit);
        if(right<limit){
            root->right = NULL;
        }
        return max(left, right);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int val = helper(root, 0, limit);
        if(val<limit) return NULL;
        return root;
        
        
    }
};