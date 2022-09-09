class Solution {
public:
    // can be solved using dfs + toposort + cycle search(not really)
    bool hasCycle(vector<int>adj[], vector<bool>&vis, int sv){
        if(vis[sv]) return true;
        vis[sv] = true;
        for(auto it:adj[sv]){
            if(hasCycle(adj, vis, it)) return true;
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>adj[n];
        vector<bool>vis(n, false);
        vector<int>indegree(n, 0);
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        int start = -1;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) start = i;
        } 
        if(start == -1) return false;
        bool flag = hasCycle(adj, vis, start);
        if(flag) return false;
        for(auto it:vis) if(it == false) return false;
        return true;
    }
};