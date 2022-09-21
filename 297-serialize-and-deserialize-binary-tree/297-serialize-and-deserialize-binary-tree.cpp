/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string encode;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr == NULL){
                encode += "#,";
                continue;
            }else{
                encode += to_string(curr->val);
                encode += ',';
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if(str != "#"){ 
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            getline(s, str, ',');
            if(str != "#"){
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));