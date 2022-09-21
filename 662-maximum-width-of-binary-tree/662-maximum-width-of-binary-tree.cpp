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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long, TreeNode*>>q;
        q.push({1, root});
        long long ans = 0;
        while(!q.empty()){
            long long currVal = q.front().first;
            long long len = q.size();
            long long first, last;
            for(int i=0;i<len;i++){
                long long val = q.front().first;
                TreeNode *currNode = q.front().second;
                q.pop();
                if(i == 0) first = val;
                if(i == len-1) last = val; 
                val = val - currVal;
                if(currNode->left) q.push({2*val + 1, currNode->left});
                if(currNode->right) q.push({2*val + 2, currNode->right});
            }
            ans = max(ans, last-first+1);
        }
        return (int)ans;
    }
};