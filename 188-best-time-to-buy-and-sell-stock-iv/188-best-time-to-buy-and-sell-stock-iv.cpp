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
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][0][j] = 0;
            }
        }
        for(int i=0;i<=k;i++){
            for(int j=0;j<=1;j++){
                dp[n][i][j] = 0;
            }
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int i=1;i<=k;i++){
                int pick = 0, notPick = 0;
                for(int buy=0;buy<=1;buy++){
                    if(buy){
                        pick = -prices[idx] + dp[idx+1][i][!buy];
                        notPick = dp[idx+1][i][buy];
                    }else{
                        pick = prices[idx] + dp[idx+1][i-1][!buy];
                        notPick = dp[idx+1][i][buy];
                    }
                    dp[idx][i][buy] = max(pick, notPick);
                }
            }
        }
        return dp[0][k][1];
    }
};