class Solution {
public:
    int findParent(int node, vector<int>&parent){
        if(parent[node] == node) return parent[node];
        return parent[node] = findParent(parent[node], parent);
    }
    void unionNodes(int u, int v, vector<int>&rank, vector<int>&parent){
        u = findParent(u, parent);
        v = findParent(v, parent);
        if(rank[u]>rank[v]){
            parent[v] = u;
        }else{
            if(rank[v]>rank[u]){
                parent[u] = v; 
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }
        return;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        set<vector<int>>s;
        int b1=-1, b2=-1;
        vector<int>parent(n+1, 0);
        vector<int>rank(n+1, 0);
        for(int i=0;i<=n;i++) parent[i] = i;
        for(int j=0;j<=n;j++) rank[j] = 0;
        vector<int>indegree(n+1, -1);
        for(int i=0;i<edges.size();i++){
            s.insert(edges[i]);
            int u = edges[i][0];
            int v = edges[i][1];
            if(indegree[v]!=-1){
                b1 = i;
                b2 = indegree[v];
                break;
            }
            indegree[v] = i;
        }
        // case 2 handling 
        if(b1==-1){
            for(int i=0;i<edges.size();i++){
                int u = edges[i][0];
                int v = edges[i][1];
                u = findParent(u, parent);
                v = findParent(v, parent);
                if(u==v){
                    return {edges[i][0], edges[i][1]};
                }else{
                    unionNodes(u,v,rank,parent);
                }
            }
        }
        // now doing for the case 3 
        for(int i=0;i<edges.size();i++){
            if(b1==i) continue;
                int u = edges[i][0];
                int v = edges[i][1];
                u = findParent(u, parent);
                v = findParent(v, parent);
                if(u==v){
                    return {edges[b2][0], edges[b2][1]};
                }else{
                    unionNodes(u,v,rank,parent);
                }
        }
        return {edges[b1][0], edges[b1][1]};
    }
    
       
};