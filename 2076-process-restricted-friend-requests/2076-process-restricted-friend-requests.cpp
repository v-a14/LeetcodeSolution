class Solution {
public:
    int findParent(int node, vector<int>&parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void doUnion(int u, int v, vector<int>&rank, vector<int>&parent){
        u = findParent(u, parent);
        v = findParent(v, parent);
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
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req){
        vector<bool>ans;
        vector<int>rank(n, 0), tempRank(n, 0);
        vector<int>parent(n, 0), tempParent(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
            tempParent[i] = i;
        }
        for(int i=0;i<req.size();i++){
            int u = req[i][0];
            int v = req[i][1];
            
            // let's first do union on temp array 
            doUnion(u,v,tempRank,tempParent);
            bool flag = true;
            for(int j=0;j<res.size();j++){
                int u = res[j][0];
                int v = res[j][1];
                if(findParent(u, tempParent) == findParent(v, tempParent)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                doUnion(u, v, rank, parent);
                ans.push_back(true);
            }else{
                tempParent = parent;
                tempRank = rank;
                ans.push_back(false);
            }
        }
        return ans;
    }
};