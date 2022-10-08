class Solution {
public:
    void merge(vector<int>&arr, int start, int mid, int end){
        vector<int>temp(end-start+1);
        int i = start, j = mid+1;
        int k = 0;
        while(i<=mid && j<=end){
            if(arr[i]>arr[j]){
                temp[k++] = arr[j++];
            }else{
                temp[k++] = arr[i++];
            }
        }
        while(i<=mid) temp[k++] =  arr[i++];
        while(j<=end) temp[k++] = arr[j++];
        k = 0;
        for(int i=start;i<=end;i++){
            arr[i] = temp[k++];
        }
        return;
    }
    void mergeSort(vector<int>&arr, int start, int end){
        if(start>=end) return;
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    vector<int> sortArray(vector<int>&arr) {
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        return arr;
    }
};