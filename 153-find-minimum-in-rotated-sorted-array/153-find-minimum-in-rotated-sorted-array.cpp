class Solution {
public:
    int findPivot(vector<int>&arr){
        int start = 0, end = arr.size() - 1;
        while(start<end){
            int mid = (start+end)/2;
            if(arr[mid]>arr[end]) start = mid+1;
            else end = mid;
        }
        return arr[start];
    }
    int findMin(vector<int>& nums) {
        return findPivot(nums);
    }
};