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
    map<TreeNode*, TreeNode*>mp;
    
    // mapping the nodes to the parent 
    void preorder(TreeNode *root, TreeNode *prev){
        if(!root) return;
        mp[root] = prev;
        preorder(root->left, root);
        preorder(root->right, root);
    }
    // TreeNode *findNode(TreeNode *root, TreeNode *target){
    //     if(!root) return NULL;
    //     if(root == target) return root;
    //     TreeNode *Left = findNode(root->left, target);
    //     if(Left) return Left;
    //     TreeNode *Right = findNode(root->right, target);
    //     if(Right) return Right;
    //     return NULL;
    // }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root, NULL);
        queue<TreeNode*>q;
        q.push(target);
        set<TreeNode*>s;
        s.insert(target);
        while(!q.empty()){
            int len = q.size();
            if(k == 0) break;
            k--;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front();
                q.pop();
                if(mp[currNode] && s.find(mp[currNode]) == s.end()){
                    q.push(mp[currNode]);
                    s.insert(mp[currNode]);
                }
                if(currNode->left && s.find(currNode->left) == s.end()){
                    q.push(currNode->left);
                    s.insert(currNode->left);
                }
                if(currNode->right && s.find(currNode->right) == s.end()){
                    q.push(currNode->right);
                    s.insert(currNode->right);
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