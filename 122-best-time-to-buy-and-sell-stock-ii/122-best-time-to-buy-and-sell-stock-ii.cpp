class Solution {
public:
    int helper(vector<int>&prices, int idx, int buy, vector<vector<int>>&dp){
        if(idx == prices.size()) return 0;
        // if buy is true, then we can buy only 
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int pick,notPick;
        if(buy){
            // again has 2 options, eighter buy or move forward 
            pick = -prices[idx] + helper(prices,idx+1,!buy, dp);
            notPick = helper(prices,idx+1, buy, dp);
        }else{
            pick = prices[idx] + helper(prices, idx+1, !buy, dp);
            notPick = helper(prices, idx+1, buy, dp);
        }
        return dp[idx][buy] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return helper(prices, 0, true, dp);
    }
};