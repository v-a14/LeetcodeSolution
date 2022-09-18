class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<long long>dis(n+1, INT_MAX);
        dis[k] = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<edges.size();j++){
                int start = edges[j][0];
                int end = edges[j][1];
                if(dis[start] + edges[j][2] < dis[end]){
                    dis[end] = dis[start] + edges[j][2];
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans, (int)dis[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};