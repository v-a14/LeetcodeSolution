class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0, j = 0;
        while(j<nums.size()){
            if(nums[j]==1) j++;
            else{
                j++;
                k--;
                while(k<0){
                    if(nums[i]==0) k++;
                    i++;
                }
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};