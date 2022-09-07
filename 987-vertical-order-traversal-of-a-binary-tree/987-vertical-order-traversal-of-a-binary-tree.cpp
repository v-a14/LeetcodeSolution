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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        map<int, vector<int>>mp;
        while(!q.empty()){
            int len = q.size();
            map<int,vector<int>>mp1;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front().first;
                int dis = q.front().second;
                q.pop();
                mp1[dis].push_back(currNode->val);
                if(currNode->left) q.push({currNode->left, dis-1});
                if(currNode->right) q.push({currNode->right, dis+1});
            }
            for(auto it = mp1.begin();it!=mp1.end();it++){
                int dis = it->first;
                sort(it->second.begin(), it->second.end());
                for(auto it1 : it->second){
                    mp[dis].push_back(it1);
                }
            }
           
        }
         vector<vector<int>>ans;
            for(auto it:mp){
                ans.push_back(it.second);
            }
        return ans;
    }
};