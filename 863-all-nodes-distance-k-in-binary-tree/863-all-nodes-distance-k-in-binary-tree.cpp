/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode*>&path){
        if(!root) return false;
        if(root == target){
            path.push_back(target);
            return true;
        }
        path.push_back(root);
        bool Left = findPath(root->left, target, path);
        if(Left) return Left;
        bool Right = findPath(root->right, target, path);
        if(Right) return Right;
        path.pop_back();
        return false;
    }
    void traversal(TreeNode *root, TreeNode *block, vector<int>&ans, int k){
        if(!root || root == block) return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        traversal(root->left, block, ans, k-1);
        traversal(root->right, block, ans, k-1);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<TreeNode*>path;
       findPath(root, target, path);
       vector<int>ans;
       for(int i=path.size()-1;i>=0;i--){
           traversal(path[i], i == path.size()-1 ? NULL : path[i+1], ans, k--);
       }
        return ans;
        
    }
};