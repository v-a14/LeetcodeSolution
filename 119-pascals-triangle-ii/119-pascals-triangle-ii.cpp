class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0) return {1};
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j == 0 || j==i){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[n];
    }
};