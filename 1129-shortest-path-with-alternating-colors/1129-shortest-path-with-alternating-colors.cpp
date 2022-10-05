class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<redEdges.size();i++){
            int start = redEdges[i][0];
            int end = redEdges[i][1];
            adj[start].push_back({end, 1});
            
        }
        for(int i=0;i<blueEdges.size();i++){
            int start = blueEdges[i][0];
            int end = blueEdges[i][1];
            adj[start].push_back({end, 0});
        }    
        
        vector<int>dis(n, 1e9);
        dis[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, -1});
        set<vector<int>>s;
        while(!pq.empty()){
            int currDis = pq.top()[0];
            int node = pq.top()[1];
            int currColor = pq.top()[2];
            pq.pop();
            for(auto it:adj[node]){
                if(it.second != currColor && dis[it.first]>currDis+1){
                    dis[it.first] = currDis + 1;
                    pq.push({dis[it.first], it.first, it.second});
                    s.insert({node, it.first, it.second});
                }else if(it.second!=currColor && s.find({node, it.first, it.second}) == s.end()){
                    pq.push({currDis+1, it.first, it.second});
                    s.insert({node, it.first, it.second});
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i] == 1e9) dis[i] = -1;
        }
        return dis;
    }
};