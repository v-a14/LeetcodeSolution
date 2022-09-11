class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            adj[start].push_back({end, cost});
        }
        vector<int>stops(n, 1e9);
        vector<int>dis(n, 1e9);
        dis[src] = 0;
        stops[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
        // current cost, starting vertex, current stops 
        q.push({0, src, 0});
        while(!q.empty()){
            int currCost = q.top()[0];
            int currNode = q.top()[1];
            int currStops = q.top()[2];
            if(currNode == dst) return currCost;
            // cout << currNode << endl;
            q.pop();
            if(currStops>k) continue;
            for(auto it:adj[currNode]){
                if((dis[it.first] > currCost + it.second) || currStops+1 < stops[it.first]){
                    stops[it.first] = currStops+1;
                    dis[it.first] = currCost + it.second;
                    q.push({dis[it.first], it.first, stops[it.first]});
                }
            }
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};