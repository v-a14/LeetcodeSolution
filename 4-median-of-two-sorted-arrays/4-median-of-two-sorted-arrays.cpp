class Solution {
public:
    double helper(vector<int>&nums1, vector<int>&nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return helper(nums2, nums1);
        int k = (n+m+1)/2;
        int minV = max(0, k-m);
        int maxV = min(n, k);
        while(minV<=maxV){
            int mid = (minV + maxV)/2;
            int rem = k - mid;
            int l1 = (mid == 0) ? INT_MIN : nums1[mid-1];
            int r1 = (mid == n) ? INT_MAX : nums1[mid];
            int l2 = (rem == 0) ? INT_MIN : nums2[rem-1];
            int r2 = (rem == m) ? INT_MAX : nums2[rem];
            if(l1<=r2 && l2<=r1){
                if((n + m)%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }else{
                if(l1>r2){
                    maxV = mid-1;
                }else{
                    minV = mid+1;
                }
            }
        }
        return nums2[0];
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2);
    }
};