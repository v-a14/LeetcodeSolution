class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n, 0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[u]++;
            indegree[v]++;
        }
        sort(indegree.begin(), indegree.end());
        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            ans += (long long)indegree[i]*(i+1);
        }
        return ans;
    }
};