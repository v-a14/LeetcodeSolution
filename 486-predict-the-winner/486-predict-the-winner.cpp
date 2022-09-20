class Solution {
public:
    int helper(vector<int>&nums, int start, int end, vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int a = nums[start] + min(helper(nums, start+2, end, dp), helper(nums, start+1, end-1, dp));
        int b = nums[end] + min(helper(nums,start+1, end-1, dp), helper(nums, start, end-2, dp));
        return dp[start][end] = max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums) sum += it;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int val = helper(nums, 0, nums.size()-1, dp);
        if(val >= (sum + 1)/2) return true;
        return false;
    }
};