class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&curr, vector<int>&nums, vector<bool>&vis, int idx){
        if(idx == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            helper(curr, nums, vis, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        vector<bool>vis(n, false);
        helper(curr, nums, vis, 0);
        return ans;
        
    }
};