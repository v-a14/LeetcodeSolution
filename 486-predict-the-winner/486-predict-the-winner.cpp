class Solution {
public:
    int helper(vector<int>&nums, int start, int end){
        if(start>end) return 0;
        int a = nums[start] + min(helper(nums, start+2, end), helper(nums, start+1, end-1));
        int b = nums[end] + min(helper(nums,start+1, end-1), helper(nums, start, end-2));
        return max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums) sum += it;
        int val = helper(nums, 0, nums.size()-1);
        if(val >= (sum + 1)/2) return true;
        return false;
    }
};