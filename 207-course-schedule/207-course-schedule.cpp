class Solution {
public:
    bool hasCycle(vector<int>adj[], vector<bool>&vis, vector<bool>&dfsVisit, int sv){
        vis[sv] = true;
        dfsVisit[sv] = true;
        for(auto it:adj[sv]){
            if(!vis[it]){
                if(hasCycle(adj, vis, dfsVisit, it)){
                    return true;
                }
            }else{
                if(dfsVisit[it]) return true;
            }
        }
        dfsVisit[sv] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            adj[start].push_back(end);
        }
        vector<bool>dfsVisit(n, false);
        vector<bool>vis(n, false);
        bool flag = false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                flag |= hasCycle(adj, vis, dfsVisit, i);
            }
        }
        return !flag;
    }
};