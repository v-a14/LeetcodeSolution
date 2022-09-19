class Solution {
public:
    static bool cmp(vector<int>&x, vector<int>&y){
        if(x[1] == y[1]) return x[0] < y[0];
        return x[1] < y[1];
    }
    int findJob(vector<vector<int>>&arr, int start, int end, int currTime){
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid][1]<=currTime){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>arr;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<int>ans(n, 0);
        ans[0] = arr[0][2];
        for(int i=1;i<n;i++){
            // let's try to find out the previous index we can get 
            int idx = findJob(arr, 0, i-1, arr[i][0]);
            if(idx == -1){
                ans[i] = max(ans[i-1], arr[i][2]);
            }else{
                ans[i] = max(ans[i-1], ans[idx] + arr[i][2]);
            }
        }
        return ans[n-1];
        
    }
};