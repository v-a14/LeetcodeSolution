class Solution {
public:
    int findMaximum(vector<int>&arr){
        int currSum = 0, maxSum = 0;
        for(int i=0;i<arr.size();i++){
            currSum += arr[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
    int findMinimum(vector<int>&arr){
        int currSum = 0, maxSum = 0;
        for(int i=0;i<arr.size();i++){
            currSum += arr[i];
            if(maxSum > currSum){
                maxSum = currSum;
            }
            if(currSum>0) currSum = 0;
        }
        return abs(maxSum);
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(findMaximum(nums), findMinimum(nums));
    }
};