#define ll long long 
class Solution {
public:
    ll helper(int n, int k, vector<vector<int>>&dp){
        if(n == 0){
            if(k>=2) return 1;
            else return -1e9;
        }
        if(dp[n][k]!=-1) return dp[n][k];
        ll ans = 0;
        ll currPro = 1;
        for(int i=1;i<=n;i++){
            ans = max(ans, i*helper(n-i, k+1, dp));
        }
        return dp[n][k] = ans;
    }
    int integerBreak(int n) {
        vector<vector<int>>dp(101, vector<int>(101, -1));
        return (int)helper(n, 0, dp);
    }
};