class Solution {
public:
    int helper(vector<int>&arr, int idx, int k, vector<int>&dp){
        if(idx == arr.size()) return 0;
        int maxi = 0, ans = 0;
        int len = 0;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<min((int)arr.size(), idx+k);i++){
            len++;
            maxi = max(maxi, arr[i]);
            ans = max(ans, len*maxi + helper(arr, i+1, k, dp));
        }
        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n, -1);
        return helper(arr, 0, k, dp);
    }
};