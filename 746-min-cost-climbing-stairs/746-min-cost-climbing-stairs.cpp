class Solution {
public:
    int helper(vector<int>&cost, int idx, vector<int>&dp){
        if(idx >= cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        // climbing 1 stair 
        int one = cost[idx] + helper(cost, idx+1, dp);
        int two = cost[idx] + helper(cost, idx+2, dp);
        return dp[idx] =  min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int ans = min(helper(cost, 0, dp), helper(cost, 1, dp));
        return ans;
    }
};