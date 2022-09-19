class Solution {
public:
    int partition(vector<int>&arr, int left, int right){
        int pivot = arr[right];
        int i = left, j = left;
        while(j<right){
            if(arr[j]<=pivot){
                swap(arr[i++], arr[j]);
            }
            j++;
        }
        swap(arr[i], arr[right]);
        return i;
    }
    int quickSelect(vector<int>&arr, int left, int right, int k){
        if(left>right) return -1;
        int mid = partition(arr, left, right);
        if(mid == k) return arr[mid];
        else if(mid>k) return quickSelect(arr, left, mid-1, k);
        else return quickSelect(arr, mid+1, right, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size()-1, k);
    }
};