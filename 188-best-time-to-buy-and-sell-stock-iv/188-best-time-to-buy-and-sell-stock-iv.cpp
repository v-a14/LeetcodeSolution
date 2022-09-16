class Solution {
public:
    int helper(vector<int>&prices, int buy, int k, int idx, vector<vector<vector<int>>>&dp){
        if(idx == prices.size() || k==0) return 0;
        int pick = 0, notPick = 0;
        if(dp[idx][k][buy]!=-1) return dp[idx][k][buy];
        if(buy){
            pick = -prices[idx] + helper(prices, !buy, k, idx+1, dp);
            notPick = helper(prices, buy, k, idx+1, dp);
        }else{
            pick = prices[idx] + helper(prices, !buy, k-1, idx+1, dp);
            notPick = helper(prices, buy, k, idx+1, dp);
        }
        return dp[idx][k][buy] = max(pick, notPick);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return helper(prices, 1, k, 0, dp);
    }
};