class Solution {
public:
    int helper(int n, int idx, vector<vector<int>>&dp){
        if(n == 0) return 1;
        if(idx == 5) return 0;
        if(dp[n][idx]!=-1) return dp[n][idx];
        // taking the current string 
        int take = helper(n-1, idx, dp);
        int notTake = helper(n, idx+1, dp);
        return dp[n][idx] = take + notTake;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1, vector<int>(5, -1));
        int ans = helper(n, 0, dp);
        return ans;
    }
};