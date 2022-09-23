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
    int count = 0;
    map<int,int> helper(TreeNode *root, int distance){
        if(!root){
            map<int,int>mp;
            return mp;
        }
        if(!root->left && !root->right){
            map<int,int>mp;
            mp[1] = 1;
            return mp;
        }
        map<int,int>left = helper(root->left, distance);
        map<int,int>right = helper(root->right, distance);
        for(auto it:left){
            for(auto it1:right){
                if(it.first + it1.first <= distance){
                    count += (it.second)*(it1.second);
                }
            }
        }
        // now update the distance by 1 
        map<int,int>temp;
        for(auto it:left) temp[it.first+1] += it.second;
        for(auto it:right) temp[it.first+1] += it.second;
        return temp;
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return count;
    }
};