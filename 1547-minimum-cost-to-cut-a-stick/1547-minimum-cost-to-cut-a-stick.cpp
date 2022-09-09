class Solution {
public:
    int helper(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int sum = 0;
        int ans = 1e9;
        for(int idx = i;idx<=j;idx++){
            sum = arr[j+1] - arr[i-1];
            // cout << sum << endl;
            ans = min(ans, sum + helper(arr, i, idx-1, dp) + helper(arr, idx+1, j, dp));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int ss = cuts.size();
        vector<vector<int>>dp(ss+1, vector<int>(ss+1, -1));
        return helper(cuts, 1, ss-2, dp);
        
    }
};