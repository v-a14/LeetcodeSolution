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
    TreeNode* helper(map<int,int>&mp, vector<int>&postorder, int &idx, int start, int end){
        if(start>end) return NULL;
        TreeNode *newNode = new TreeNode(postorder[idx]);
        int indexInInorder = mp[postorder[idx--]];
        newNode->right = helper(mp, postorder, idx, indexInInorder+1, end);
        newNode->left = helper(mp, postorder, idx, start, indexInInorder-1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int n = inorder.size();
        int idx = n-1;
        return helper(mp, postorder, idx, 0, n-1);
    }
};