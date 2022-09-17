class Solution {
public:
    bool check(vector<int>&weight, long long capacity, int days){
        long long temp = capacity;
        int currDays = 1;
        for(int i=0;i<weight.size();i++){
            if(capacity<weight[i]) return false;
            if(temp>=weight[i]){
                temp-=weight[i];
            }else{
                temp = capacity - weight[i];
                currDays++;
            }
        }
        return currDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long int start = 1, end = 1e9;
        int ans = 0;
        while(start<=end){
            long long mid = (start+end)/2;
            if(check(weights, mid, days)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};