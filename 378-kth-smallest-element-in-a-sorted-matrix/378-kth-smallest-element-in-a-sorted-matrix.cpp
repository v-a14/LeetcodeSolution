class Solution {
public:
    int upperBound(vector<int>&arr, long long x){
        int start = 0, end = arr.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]<=x) start = mid+1;
            else end = mid-1;
        }
        return start;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long start = -1e9, end = 1e9;
        int n = matrix.size();
        int m = matrix[0].size();
        while(start<=end){
            long long mid = (start+end)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                count += upperBound(matrix[i], mid);
            }
            if(count<k) start = mid+1;
            else end = mid-1;
        }
        return start;
    }
};