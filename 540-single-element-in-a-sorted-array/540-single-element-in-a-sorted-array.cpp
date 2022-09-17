class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid==0 || mid==arr.size()-1 || (arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])) return arr[mid];
            else if(mid%2==0){
                if(arr[mid+1] == arr[mid]) low = mid+1;
                else high = mid-1;
            }else{
                if(arr[mid-1] == arr[mid]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};