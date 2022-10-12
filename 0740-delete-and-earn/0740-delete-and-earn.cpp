class Solution {
public:
    int helper(vector<int>&arr,int idx, vector<int>&dp){
        if(idx == arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = 0, notPick = 0;
        int currNum = arr[idx];
        int currSum = 0;
        int tempIdx1 = idx;
        while(tempIdx1<arr.size() && arr[tempIdx1] == currNum){
            currSum += arr[tempIdx1++];
        }
        int tempIdx2 = tempIdx1;        
        while(tempIdx2<arr.size() && arr[tempIdx2] == currNum+1) tempIdx2++;
        
        // now I have two choices 
        pick = currSum + helper(arr, tempIdx2, dp);
        notPick = helper(arr, tempIdx1, dp);
        return dp[idx] = max(pick, notPick);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return helper(nums, 0, dp);
    }
};