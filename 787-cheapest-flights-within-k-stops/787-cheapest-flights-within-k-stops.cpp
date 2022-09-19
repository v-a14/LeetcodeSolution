class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int start = flights[i][0];
            int end = flights[i][1];
            int weight = flights[i][2];
            adj[start].push_back({end, weight});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, src, 0});
        vector<int>dis(n, 1e9);
        vector<int>stops(n, 1e9);
        dis[src] = 0;
        stops[src] = 0;
        while(!pq.empty()){
            int node = pq.top()[1];
            int currWeight = pq.top()[0];
            int currStops = pq.top()[2];
            if(node == dst) return currWeight; 
            pq.pop();
            if(currStops > k) continue;
            for(auto it:adj[node]){
                if((dis[it.first] > currWeight + it.second)  || currStops+1<stops[it.first]){
                    dis[it.first] = currWeight + it.second;
                    stops[it.first] = currStops + 1;
                    pq.push({dis[it.first], it.first, stops[it.first]});
                }
            }
        }
        return -1;
    }
};