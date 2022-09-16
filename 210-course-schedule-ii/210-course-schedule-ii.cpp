class Solution {
public:
    bool isCycle(vector<int>adj[], vector<bool>&vis, vector<bool>&dfsVisit, int sv){
        vis[sv] = true;
        dfsVisit[sv] = true;
        for(auto it:adj[sv]){
            if(!vis[it]){
                if(isCycle(adj, vis, dfsVisit, it)) return true;
            }else{
                if(dfsVisit[it]){
                    return true;
                }
            }
        }
        dfsVisit[sv] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>&edges) {
        vector<int>adj[n];
        vector<int>indegree(n, 0);
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            adj[end].push_back(start);
            indegree[start]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int>ans;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            count++;
            for(auto it:adj[currNode]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            ans.push_back(currNode);
        }
        if(count!=n) return {};
        return ans;
    }
};