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
    TreeNode *helper(vector<int>&preorder, map<int,int>&mp, int &idx, int start, int end){
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(preorder[idx]);
        int indexInInorder = mp[preorder[idx++]];
        root->left = helper(preorder, mp, idx, start, indexInInorder-1);
        root->right = helper(preorder, mp, idx, indexInInorder+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return helper(preorder, mp, idx, 0, n-1);
    }
};