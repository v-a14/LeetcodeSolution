class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int minDiff = 1e9;
        int ans = 0;
        for(int i=0;i<arr.size()-2;i++){
            int j = i+1, k = arr.size()-1;
            while(j<k){
                int val = arr[i]+arr[j]+arr[k];
                if(abs(target-val)<minDiff){
                    minDiff = abs(target-val);
                    ans = arr[i] + arr[j] + arr[k];
                }
                if(val > target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};