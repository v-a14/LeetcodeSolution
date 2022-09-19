class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9;
        int currPro = 1;
        for(int i=0;i<nums.size();i++){
            currPro *= nums[i];
            ans = max(currPro, ans);
            if(currPro == 0) currPro = 1;
        }
        currPro = 1;
        for(int i=nums.size()-1;i>=0;i--){
            currPro *= nums[i];
            ans = max(ans, currPro);
            if(currPro == 0) currPro = 1;
        }
        return ans;
    }
};