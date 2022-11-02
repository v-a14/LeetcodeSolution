class Solution {
public:
    void dfs(vector<int>adj[], int sv, vector<bool>&vis){
        vis[sv] = true;
        for(auto it:adj[sv]){
            if(!vis[it]){
                dfs(adj, it, vis);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:rooms[i]){
                adj[i].push_back(it);
            }
        }
        vector<bool>vis(n, false);
        dfs(adj, 0, vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};