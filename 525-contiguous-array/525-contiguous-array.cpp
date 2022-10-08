class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        mp[0] = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        int ans = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp.find(sum)==mp.end()) mp[sum] = i+1;
            else ans = max(ans, i+1-mp[sum]);
        }
        return ans;
        
    }
};