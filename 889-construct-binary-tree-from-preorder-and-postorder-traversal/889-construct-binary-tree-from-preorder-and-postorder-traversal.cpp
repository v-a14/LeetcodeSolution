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
    TreeNode *helper(vector<int>&preorder, int &idx, map<int,int>&postorder, int start, int end){
        if(start > end) return NULL;
        if(start == end){
            return new TreeNode(preorder[idx++]);
        }
        TreeNode *root = new TreeNode(preorder[idx++]);
        int indexInPostorder = postorder[preorder[idx]];
        root->left = helper(preorder, idx, postorder, start, indexInPostorder);
        root->right = helper(preorder, idx, postorder, indexInPostorder+1, end-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }
        int idx = 0;
        int n = preorder.size();
        return helper(preorder, idx, mp, 0, n-1);
    }
};