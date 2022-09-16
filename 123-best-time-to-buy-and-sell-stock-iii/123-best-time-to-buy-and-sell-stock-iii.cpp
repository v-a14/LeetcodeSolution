class Solution {
public:
    int helper(vector<int>&prices, int buy, int idx, int k, vector<vector<vector<int>>>&dp){
        if(idx == prices.size() || k == 0) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        int pick, notPick;
        if(buy){
            pick = -prices[idx] + helper(prices, !buy, idx+1, k, dp);
            notPick = helper(prices, buy, idx+1, k, dp);
        }else{
            pick = prices[idx] + helper(prices, !buy, idx+1, k-1, dp);
            notPick = helper(prices, buy, idx+1, k, dp);
        }
        return dp[idx][buy][k] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 1, 0, 2, dp);
    }
};