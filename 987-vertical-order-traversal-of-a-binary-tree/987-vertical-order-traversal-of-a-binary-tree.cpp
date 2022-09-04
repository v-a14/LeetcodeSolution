class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map chaiye jo har motai ke liye, vector mei data daalta jaaega 
        map<int, vector<int>>mp;
        // queue chaiye h ek to store node, aur uski motai kitni h 
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int len = q.size();
            multiset<pair<int,int>>s;
            while(len--){
                TreeNode *curr = q.front().first;
                int width = q.front().second;
                q.pop();
                s.insert({curr->val, width});
                // mp[width].push_back(curr->val);
                if(curr->left){
                    q.push({curr->left, width-1});
                }
                if(curr->right){
                    q.push({curr->right, width+1});
                }
            }
            for(auto it:s){
                mp[it.second].push_back(it.first);
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            // sort(it.second.begin(), it.second.end());
            ans.push_back(it.second);
        }
        return ans;
    }
};