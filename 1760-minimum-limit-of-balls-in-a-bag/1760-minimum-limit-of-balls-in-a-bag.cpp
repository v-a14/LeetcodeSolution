class Solution {
public:
    bool check(vector<int>&nums, int maxOperations, int val){
        int operations = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%val == 0){
                operations += (nums[i]/val - 1);
            }else{
                operations += nums[i]/val;
            }
        }
        return operations <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1, end = 1e9;
        int ans = 0;
        while(start<=end){
            int mid = (start+end)/2;
            if(check(nums, maxOperations, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};