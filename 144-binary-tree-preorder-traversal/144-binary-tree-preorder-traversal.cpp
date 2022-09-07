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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top()->val);
            TreeNode *currNode = st.top();
            st.pop();
            if(currNode->right) st.push(currNode->right);
            if(currNode->left) st.push(currNode->left);
        }
        return ans;
    }
};