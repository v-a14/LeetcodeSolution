class Solution {
public:
    bool isBipartite(vector<vector<int>>&adj, int sv, vector<int>&color){
        if(color[sv] == -1){
            color[sv] = 1;
        }
        for(auto it:adj[sv]){
            if(color[it] == -1){
                color[it] = 1 - color[sv];
                if(!isBipartite(adj, it, color)){
                    return false;
                }
            }else{
                if(color[it] == color[sv]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!isBipartite(graph, i, color)) return false;
            }
        }
        return true;
    }
};