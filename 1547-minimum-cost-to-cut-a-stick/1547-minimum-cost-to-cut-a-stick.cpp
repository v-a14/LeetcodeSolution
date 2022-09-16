class Solution {
public:
    int helper(vector<int>&cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        int ans = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            ans = min(ans, cuts[j+1] - cuts[i-1] + helper(cuts, i, idx-1, dp) + helper(cuts, idx+1, j, dp));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1, -1));
        return helper(cuts, 1, (int)cuts.size()-2, dp);
        
    }
};