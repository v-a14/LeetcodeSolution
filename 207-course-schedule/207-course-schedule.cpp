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
        vector<int>indegree(n, 0);
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            indegree[end]++;
            adj[start].push_back(end);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return count == n;
    }
};