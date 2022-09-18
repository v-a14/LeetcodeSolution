class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&curr, vector<int>&nums, vector<bool>&vis, int count){
        if(count == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = true;
                curr.push_back(nums[i]);
                helper(curr, nums, vis, count+1);
                curr.pop_back();
                vis[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        vector<bool>vis(n, false);
        helper(curr, nums, vis, 0);
        return ans;
        
    }
};