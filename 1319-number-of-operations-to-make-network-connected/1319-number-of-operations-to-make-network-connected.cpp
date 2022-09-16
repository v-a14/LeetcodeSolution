class Solution {
public:
    void dfs(vector<int>adj[], vector<bool>&vis, int sv){
        vis[sv] = true;
        for(auto it:adj[sv]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& edges){
        int wires = edges.size();
        if(wires<n-1) return -1;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        vector<bool>vis(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(adj, vis, i);
            }
        }
        return count-1;
        
    }
};