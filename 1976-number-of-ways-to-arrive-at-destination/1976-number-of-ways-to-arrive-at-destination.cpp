#define ll long long 
#define mod 1000000007 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            int start = roads[i][0];
            int end = roads[i][1];
            int time = roads[i][2];
            adj[start].push_back({end, time});
            adj[end].push_back({start, time});
        }
        vector<pair<ll,ll>>dis(n, {1e18,0});
        dis[0].first = 0;
        dis[0].second = 1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        pq.push({0, 0});
        while(!pq.empty()){
            ll currNode = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
            for(auto it:adj[currNode]){
                if(dis[it.first].first > d + it.second){
                    dis[it.first].first = d + it.second;
                    dis[it.first].second = dis[currNode].second;
                    pq.push({dis[it.first].first, it.first});
                }else{
                    if(dis[it.first].first == d + it.second){
                        dis[it.first].second = (dis[it.first].second + dis[currNode].second)%mod;
                    }
                }
            }
        }
        return dis[n-1].second;
    }
};