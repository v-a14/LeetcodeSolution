class Solution {
public:
    int helper(vector<int>&arr, int i, int k, vector<int>&dp){
        if(i == arr.size()) return 0;
        int ans = 0, maxi = 0, len = 0;
        if(dp[i]!=-1) return dp[i];
        for(int idx=i; idx<min(i+k, (int)arr.size()); idx++){
            maxi = max(maxi, arr[idx]);
            len++;
            ans = max(ans, maxi*len + helper(arr, idx+1, k, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return helper(arr, 0, k, dp);
    }
};