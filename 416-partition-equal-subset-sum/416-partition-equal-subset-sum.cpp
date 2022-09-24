class Solution {
public:
    bool helper(vector<int>&nums, int idx, int sum, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(idx<0) return false;
        bool pick = false, notPick = false;
        if(dp[sum][idx]!=-1) return dp[sum][idx];
        if(sum>=nums[idx]) pick = helper(nums, idx-1, sum-nums[idx], dp);
        notPick = helper(nums, idx-1, sum, dp);
        return dp[sum][idx] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums) sum += it;
        if(sum%2!=0) return false;
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(sum+1, vector<int>(n+1, -1));
        return helper(nums, n-1, sum, dp);
    }
};