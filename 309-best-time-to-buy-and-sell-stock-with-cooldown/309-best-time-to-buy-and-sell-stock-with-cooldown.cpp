class Solution {
public:
    int helper(vector<int>&prices, int buy, int idx, vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        int pick, notPick;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            pick = -prices[idx] + helper(prices, !buy, idx+1, dp);
            notPick = helper(prices, buy, idx+1, dp);
        }else{
            pick = prices[idx] + helper(prices, !buy, idx+2, dp);
            notPick = helper(prices, buy, idx+1, dp);
        }
        return dp[idx][buy] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(prices, 1, 0, dp);
    }
};