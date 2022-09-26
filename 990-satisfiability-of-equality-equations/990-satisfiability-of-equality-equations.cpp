class Solution {
public:
    int getParent(int node, vector<int>&parent){
        if(node==parent[node])
            return node;
        return parent[node] = getParent(parent[node], parent);
    }
    void doUnion(int u, int v, vector<int>&rank, vector<int>&parent){
        u = getParent(u, parent);
        v = getParent(v, parent);
        if(u==v) return;
        if(rank[u]>rank[v]){
            parent[v] = u;
        }else{
            if(rank[v]>rank[u]){
                parent[u] = v;
            }else{
                rank[u]++;
                parent[v] = u;
            }
        }
        return;
    }
    bool equationsPossible(vector<string>&edges) {
        vector<int>rank(27, 0);
        vector<int>parent(27, 0);
        for(int i=0;i<=26;i++){
            rank[i] = 0;
            parent[i] = i;
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0]-'a';
            int v = edges[i][3]-'a';
            if(edges[i][1] != '!'){
                doUnion(u,v,rank,parent);
            }
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0]-'a';
            int v = edges[i][3]-'a';
            if(edges[i][1] == '!'){
                u = getParent(u, parent);
                v = getParent(v, parent);
                if(u == v) return false;
            }
        }
        return true;
    }
};