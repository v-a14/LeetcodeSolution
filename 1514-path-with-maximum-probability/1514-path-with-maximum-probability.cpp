class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            double pro = succProb[i];
            adj[start].push_back({end, pro});
            adj[end].push_back({start, pro});
        }
        vector<double>dis(n, 0.0);
        priority_queue<pair<double, int>>pq;
        dis[start] = 1.0;
        pq.push({1.0, start});
        while(!pq.empty()){
            double currDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis[it.first] < currDis*it.second){
                    dis[it.first] = currDis*it.second;
                    pq.push({currDis*it.second, it.first});
                }
            }
        }
        return dis[end];
    }
};