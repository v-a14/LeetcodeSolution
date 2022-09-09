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
    void traversal(TreeNode *root, vector<int>&ans){
        if(!root) return;
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1, r2;
        traversal(root1, r1);
        traversal(root2, r2);
        vector<int>res;
        int i = 0, j = 0;
        while(i<r1.size() && j<r2.size()){
            if(r1[i] > r2[j]){
                res.push_back(r2[j++]);
            }else{
                res.push_back(r1[i++]);
            }
        }
        while(i<r1.size()) res.push_back(r1[i++]);
        while(j<r2.size()) res.push_back(r2[j++]);
        return res;
    }
};