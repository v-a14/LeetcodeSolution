class Solution {
public:
    int helper(vector<vector<int>>&arr, int prevIdx, int idx, vector<vector<int>>&dp){
        if(idx == arr.size()) return 0;
        if(prevIdx!=-1) if(dp[prevIdx][idx]!=-1) return dp[prevIdx][idx];
        int pick = 0, notPick = 0;
        if(prevIdx == -1){
            pick = 1 + helper(arr, idx, idx+1, dp);
        }else
        if(arr[idx][0]>arr[prevIdx][1]){
            pick = 1 + helper(arr, idx, idx+1, dp);
        }
        notPick = helper(arr, prevIdx, idx+1, dp);
        if(prevIdx!=-1)
            return dp[prevIdx][idx] = max(pick, notPick);
        return max(pick, notPick);
    }
    static bool cmp(vector<int>&x, vector<int>&y){
        return x[0] < y[0];
    }
    int findLongestChain(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(arr, -1, 0, dp);
    }
};