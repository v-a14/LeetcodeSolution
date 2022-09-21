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
    TreeNode* helper(map<int,int>&mp, vector<int>&preorder, int &idx, int start, int end){
        if(start>end) return NULL;
        if(start==end) return new TreeNode(preorder[idx++]);
        TreeNode *currNode = new TreeNode(preorder[idx++]);
        int index = mp[preorder[idx]];
        currNode->left = helper(mp, preorder, idx, start, index);
        currNode->right = helper(mp, preorder, idx, index+1, end-1);
        return currNode;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }
        int idx = 0;
        return helper(mp, preorder, idx, 0, postorder.size()-1);
    }
};