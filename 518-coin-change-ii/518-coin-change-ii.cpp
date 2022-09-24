class Solution {
public:
    int helper(int amount, vector<int>&coins, int idx, vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(idx<0) return 0;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int pick = 0, notPick = 0;
        if(amount>=coins[idx]) pick = helper(amount-coins[idx], coins, idx, dp);
        notPick = helper(amount, coins, idx-1, dp);
        return dp[amount][idx] = pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1, vector<int>(n+1, -1));
        return helper(amount, coins, n-1, dp);
    }
};