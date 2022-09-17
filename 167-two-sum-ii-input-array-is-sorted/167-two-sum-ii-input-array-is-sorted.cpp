class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;
        while(start<=end){
            if(arr[start] + arr[end] == target) return {start+1, end+1};
            else if(arr[start] + arr[end] > target) end--;
            else start++;
        }
        return {};
    }
};