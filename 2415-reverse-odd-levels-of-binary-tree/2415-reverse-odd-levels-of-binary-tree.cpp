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
    queue<TreeNode*> reverseQ(queue<TreeNode*>q){
        stack<TreeNode*>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        return q;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        TreeNode *newRoot = root;
        while(!q.empty()){
            int len = q.size();
            level++;
            queue<TreeNode*>par = q;
            for(int i=0;i<len;i++){
                TreeNode *currNode = q.front();
                q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(q.empty()) continue;
            queue<TreeNode*>q1 = q;
            if(level%2!=0){
                q1 = reverseQ(q1);
            }else{
                par = reverseQ(par);
            }
            for(int i=0;i<len;i++){
                TreeNode *currNode = par.front();
                par.pop();
                TreeNode *leftChild = q1.front();
                q1.pop();
                TreeNode *rightChild = q1.front();
                q1.pop();
                currNode->left = leftChild;
                currNode->right = rightChild;
            }
        }
        return newRoot;
    }
};