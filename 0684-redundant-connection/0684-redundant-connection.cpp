class Solution {
public:
    int getParent(int node, vector<int>&parent){
        if(node == parent[node]) return node;
        return parent[node] = getParent(parent[node], parent);
    }
    void doUnion(int u, int v,  vector<int>&rank, vector<int>&parent){
        u = getParent(u, parent);
        v = getParent(v, parent);
        if(rank[u]>rank[v]){
            parent[v] = u;
        }else{
            if(rank[v] > rank[u]){
                parent[u] = v;
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n, 0);
        vector<int>rank(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u--; v--;
            u = getParent(u, parent);
            v = getParent(v, parent);
            if(u == v){
                return {edges[i][0], edges[i][1]};
            }
            doUnion(u, v, rank, parent);
        }
        return {};
    }
};