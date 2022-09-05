/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};    
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>temp;
            int len = q.size();
            while(len--){
                Node *currNode = q.front();
                q.pop();
                for(auto it : currNode->children){
                    q.push(it);
                }
                temp.push_back(currNode->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};