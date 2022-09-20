class Solution {
public:
    bool check(vector<int>&nums, long long maxSum, int m){
        long long currsum = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxSum) return false;
            if(currsum+nums[i]<=maxSum){
                currsum += nums[i];
            }else{
                currsum = nums[i];
                count++;
            }
        }
        return count<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        long long start = 0, end = 1e9;
        int ans = 0;
        while(start<=end){
            long long mid = (start+end)/2;
            if(check(nums, mid, m)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};