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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;
        bool flag = false;
        while(!q.empty()){
            int len = q.size();
            flag = !flag;
            vector<int>ans;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front();
                q.pop();
                ans.push_back(currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(!flag){
                reverse(ans.begin(), ans.end()) ;
                v.push_back(ans);
            }else{
                v.push_back(ans);
            }
        }
        return v;
    }
};