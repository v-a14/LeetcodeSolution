class Solution {
public:
    int helper(int start, int idx, vector<int>&nums, vector<int>&mul, vector<vector<int>>&dp){
        if(idx == mul.size()) return 0;
        // taking from left
        int n = nums.size();
        if(dp[start][idx]!=-1) return dp[start][idx];
        int left = nums[start]*mul[idx] + helper(start+1, idx+1, nums, mul, dp);
        int end = (n-1) - (idx - start);
        int right = nums[end]*mul[idx] + helper(start, idx+1, nums, mul, dp);
        return dp[start][idx] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1, 0));
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int left = nums[j]*mul[i] + dp[i+1][j+1];
                int end = (n-1) - (i - j);
                int right = nums[end]*mul[i] + dp[i+1][j];
                dp[i][j] = max(left, right);
            }
        }
        return dp[0][0];
    }
};