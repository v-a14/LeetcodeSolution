class Solution {
public:
    int helper(vector<int>&arr, int idx, int time, vector<vector<int>>&dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][time]!=-1) return dp[idx][time];
        int pick = -1e9, notPick = -1e9;
        pick = time*arr[idx] + helper(arr, idx+1, time+1, dp);
        notPick = helper(arr, idx+1, time, dp);
        return dp[idx][time] = max(pick, notPick);
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(1001, vector<int>(1001, -1));
        return helper(arr, 0, 1, dp);
    }
};