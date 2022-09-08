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
#define ll long long 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>>q;
        q.push({root, 1});
        ll ans = 0;
        while(!q.empty()){
            ll len = q.size();
            ll delVal = q.front().second;
            ll first = -1, last = -1;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front().first;
                ll dis = q.front().second - delVal;
                q.pop();
                if(i == 0) first = dis;
                if(i == len-1) last = dis;
                if(currNode->left){
                    q.push({currNode->left, 2*dis + 1});
                }
                if(currNode->right){
                    q.push({currNode->right, 2*dis + 2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return (int)ans;
    }
};