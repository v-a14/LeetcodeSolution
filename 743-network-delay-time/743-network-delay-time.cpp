class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        // let's try by using djikstra's algorithm 
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            int weight = edges[i][2];
            start--; end--;
            adj[start].push_back({end, weight});
        }
        vector<int>dis(n, INT_MAX);
        dis[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, k-1});
        while(!pq.empty()){
            int currNode = pq.top().second;
            int disTillcurr = pq.top().first;
            pq.pop();
            for(auto it:adj[currNode]){
                if(dis[it.first] > dis[currNode] + it.second){
                    dis[it.first] = dis[currNode] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
            
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, dis[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};