class Solution {
public:
    int helper(int eggs, int k, vector<vector<int>>&dp){
        if(eggs == 0) return 1e9;
        if(k == 0 || k==1) return 1;
        if(eggs == 1) return k;
        int ans = 1e9;
        if(dp[k][eggs]!=-1) return dp[k][eggs];
        for(int i=1;i<=k;i++){
            int breaks = helper(eggs-1, i-1, dp);
            int notBreaks = helper(eggs, k - i, dp);
            int val = 1 + max(breaks, notBreaks);
            ans = min(ans, val);
        }
        return dp[k][eggs] = ans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return helper(2, n, dp);
    }
};