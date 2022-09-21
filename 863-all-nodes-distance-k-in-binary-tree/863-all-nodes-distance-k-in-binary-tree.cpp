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
    void mapParent(TreeNode *root, map<TreeNode*, TreeNode*>&mp, TreeNode *prev){
        if(!root) return;
        mp[root] = prev;
        mapParent(root->left, mp, root);
        mapParent(root->right, mp, root);
        return;   
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*>mp;
        mapParent(root, mp, NULL);
        // now can do the bfs traversal and reach the nodes at distance of k ;
        queue<TreeNode*>q;
        q.push(target);
                set<TreeNode*>vis;

        vis.insert(target);
        while(!q.empty() && k>0){
            int len = q.size();
            k--;
            cout << len << endl;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front();
                cout << currNode->val << " ";
                q.pop();
                if(vis.find(currNode->left) == vis.end() && currNode->left){
                    q.push(currNode->left);
                    vis.insert(currNode->left);
                }
                if(vis.find(currNode->right) == vis.end() && currNode->right){
                    vis.insert(currNode->right);
                    q.push(currNode->right);
                }
                if(vis.find(mp[currNode]) == vis.end() && mp[currNode]){
                    vis.insert(mp[currNode]);
                    q.push(mp[currNode]);
                }
            }
        }
                            
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};