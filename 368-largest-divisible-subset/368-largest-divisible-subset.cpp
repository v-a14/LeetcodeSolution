class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), hash(n, 0);
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int temp = 1, ind = 0;
        for(int i=1;i<nums.size();i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j; 
                }
            }
            if(dp[i] > temp){
                temp = dp[i];
                ind = i;
            }
        }
        
        while(ind != hash[ind]){
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};