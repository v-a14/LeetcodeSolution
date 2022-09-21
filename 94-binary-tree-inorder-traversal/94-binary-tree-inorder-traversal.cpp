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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode *curr = root;
        vector<int>ans;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            if(!st.empty()){
                curr = st.top();
                ans.push_back(st.top()->val);
                st.pop();
            }
            curr = curr->right;
        }
        return ans;
    }
};