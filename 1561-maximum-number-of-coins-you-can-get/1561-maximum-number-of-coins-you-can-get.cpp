class Solution {
public:
    int maxCoins(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int run = arr.size()/3;
        int j = arr.size()-2;
        int ans = 0;
        while(run--){
            ans += arr[j];
            j-=2;
        }
        return ans;
    }
};