class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(i==1 || nums[i]>=nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return count<=1;
    }
};