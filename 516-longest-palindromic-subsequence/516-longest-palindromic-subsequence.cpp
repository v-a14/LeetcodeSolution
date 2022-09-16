class Solution {
public:
    string reverse(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
    int helper(int idx1, int idx2, string t, string s, vector<vector<int>>&dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]) return dp[idx1][idx2] = 1 + helper(idx1-1, idx2-1, t, s, dp);
        else return dp[idx1][idx2] = max(helper(idx1-1, idx2, t, s, dp), helper(idx1, idx2-1, t, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        string t = reverse(s);
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int idx1=1; idx1<=n; idx1++){
            for(int idx2=1; idx2<=n; idx2++){
                if(s[idx1-1] == t[idx2-1]) dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                else dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
            }
        }
        return dp[n][n];
    }
};