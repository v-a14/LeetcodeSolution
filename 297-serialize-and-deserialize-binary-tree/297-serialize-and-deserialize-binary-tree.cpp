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
    // kuch nhi krenge bas null k jagah '#' daal denge, aur ek value ke baad ',' jisse separate kr skte 
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);
        string str = "";
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            if(currNode)
                str += to_string(currNode->val);
            else str += '#';
            str += ',';
            if(currNode){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
            return str;
    }


    // Decodes your encoded data to tree.
    // string ko parse kr lenge, aur har ek ',' isse pehle ka pura element process krenge 
    // agar null hoga, toh matlab hamare pass '#' aaya hoga, toh bas hum uss node mei 
    // null daal denge 
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            // checking the left part of the current node
            // if it is "#", then add null, other wise add the number 
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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));