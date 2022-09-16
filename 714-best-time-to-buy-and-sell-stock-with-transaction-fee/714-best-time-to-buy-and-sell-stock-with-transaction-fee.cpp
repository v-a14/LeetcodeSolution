class Solution {
public:
    int helper(vector<int>&prices, int idx, int fee, int buy, vector<vector<int>>&dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int pick, notPick;
        if(buy){
            pick = -prices[idx] + helper(prices, idx+1, fee, !buy, dp);
            notPick = helper(prices, idx+1, fee, buy, dp);
        }else{
            pick = prices[idx] - fee + helper(prices, idx+1, fee, !buy, dp);
            notPick = helper(prices, idx+1, fee, buy, dp);
        }
        return dp[idx][buy] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(prices, 0, fee, 1, dp);
    }
};