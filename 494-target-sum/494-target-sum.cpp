class Solution {
public:
    int helper(vector<int>&nums, int target, int idx, vector<vector<int>>&dp){
        if(idx<0){
            if(target == 1000) return 1;
            return 0;
        }
        if(dp[target][idx]!=-1) return dp[target][idx];
        int pick = 0, notPick = 0;
        if(nums[idx]<=target-1000) pick = helper(nums, target-nums[idx], idx-1, dp);
        notPick = helper(nums, target, idx-1, dp);
        return dp[target][idx] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int count = 0;
        for(auto it:nums){
            sum += it;
            if(it == 0) count++;
        }
        if((sum + target)%2!=0) return 0;
        sum = (sum+target)/2;
        sum += 1000;
        int n = nums.size();
        vector<vector<int>>dp(sum+1, vector<int>(n+1, -1));
        return helper(nums, sum, n-1, dp);
    }
};