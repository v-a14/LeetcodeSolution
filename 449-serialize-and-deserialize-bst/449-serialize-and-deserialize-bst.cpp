/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            if(currNode){
                str += to_string(currNode->val);
                str += ',';
            }else{
                str += "#,";
            }
            if(currNode){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        if(data.size() == 0) return NULL;
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                currNode->left = NULL;
            }else{
                currNode->left = new TreeNode(stoi(str));
                q.push(currNode->left);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                currNode->right = NULL;
            }else{
                currNode->right = new TreeNode(stoi(str));
                q.push(currNode->right);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;