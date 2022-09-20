class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;
        while(start<=end){

            int mid = (start+end)/2;
            // cout << mid << endl;
            if(arr[mid] == target) return true;
            if(arr[mid] == arr[start] && arr[mid] == arr[end]){
                start++;
                end--;
                continue;
            }
            // left side is sorted 
            if(arr[mid]>=arr[start]){
                if(arr[start]<=target && arr[mid]>=target) end = mid-1;
                else start = mid+1;    
            }else{
                // right side is sorted
                if(arr[mid]<=target && target<=arr[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return false;
    }
};