class Solution {
public:
    long long helper(vector<int>&nums, int idx, int even, vector<vector<long long>>&dp){
        if(idx == nums.size()) return 0;
        long long pick = 0, notPick = 0;
        if(dp[idx][even] != -1) return dp[idx][even];
        if(even){
            pick = nums[idx] + helper(nums, idx+1, !even, dp);
            notPick = helper(nums, idx+1, even, dp);
        }else{
            pick = -nums[idx] + helper(nums, idx+1, !even, dp);
            notPick = helper(nums, idx+1, even, dp);
        }
        return dp[idx][even] = max(pick, notPick);
        
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n+1, vector<long long>(2, -1));
        return helper(nums, 0, true, dp);
    }
};