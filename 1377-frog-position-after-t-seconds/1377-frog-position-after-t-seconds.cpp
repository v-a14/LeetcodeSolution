class Solution {
public:
    double dfs(vector<int>adj[], int sv, int time, int target, vector<bool>&vis){
        if((sv!=1 && adj[sv].size() == 1) || time == 0){
            // will return 1.00 if target ke equla
            // else return 0.00
            return sv == target;
        }
        vis[sv] = true;
        double res = 0.0;
        for(auto it:adj[sv]){
            if(!vis[it]){
                 res += dfs(adj, it, time-1, target, vis);
            }
        }
        return res/(adj[sv].size() - (sv!=1));
        
        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size() == 0 && target == 1) return 1.00;
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        vector<bool>vis(n+1, false);
        return dfs(adj, 1, t, target, vis);
    }
};