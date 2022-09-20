class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(arr[mid] > arr[end]){
                start = mid+1;
            }else{
                if(arr[mid]<arr[end]){
                    end = mid;
                }else{
                    end--;
                }
            }
        }
        return arr[start];
    }
};