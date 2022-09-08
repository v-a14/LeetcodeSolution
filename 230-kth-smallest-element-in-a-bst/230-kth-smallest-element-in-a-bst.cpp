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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode *currNode = root;
        while(currNode || !st.empty()){
            while(currNode){
                st.push(currNode);
                currNode = currNode->left;
            }
            k--;
            if(k == 0) return st.top()->val;
            currNode = st.top();
            currNode = currNode->right;
            st.pop();
        }
        return -1;
    }
};