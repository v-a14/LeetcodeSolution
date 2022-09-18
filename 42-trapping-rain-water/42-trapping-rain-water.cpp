class Solution {
public:
    int trap(vector<int>& arr) {
        int leftMax = 0, rightMax = 0;
        int left = 0, right = arr.size()-1;
        int count = 0;
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(leftMax<=arr[left]) leftMax = arr[left];
                else count += (leftMax - arr[left]);
                left++;
            }else{
                if(rightMax<=arr[right]) rightMax = arr[right];
                else count += (rightMax - arr[right]);
                right--;
            }
        }
        return count;
    }
};