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
    int convert(string temp){
        int n = temp.size()-1;
        int sum = 0;
        for(int i=0;i<temp.size();i++){
            sum += (temp[i] - '0')*(pow(2, n--));
        }
        return sum;
    }
    int helper(TreeNode *root, string temp){
        if(!root) return 0;
        if(!root->left && !root->right){
            temp += (char)(root->val + '0');
            return convert(temp);
        }
        temp += (char)(root->val + '0');
        return helper(root->left, temp) + helper(root->right, temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp;
        return helper(root, temp);
        
    }
};