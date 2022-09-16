class Solution {
public:
    int helper(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        int ans = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            int val = arr[i-1]*arr[idx]*arr[j+1] + helper(arr, i, idx-1, dp) + helper(arr, idx+1, j, dp);
            ans = max(ans, val);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);
        for(auto it:nums) arr.push_back(it);
        arr.push_back(1);
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(arr, 1, (int)arr.size()-2, dp);
    }
};