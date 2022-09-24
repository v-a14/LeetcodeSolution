class Solution {
public:
    pair<int,int>getCount(string s){
        int ones = 0, zeroes = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') zeroes++;
            else ones++;
        }
        return {zeroes, ones};
    }
    int helper(map<string, pair<int,int>>&mp, vector<string> &s, int m, int n, int idx, vector<vector<vector<int>>>&dp){
        if(idx<0) return 0;
        if(dp[m][n][idx]!=-1) return dp[m][n][idx]; 
        int pick = 0, notPick = 0;
        if(mp[s[idx]].first<=m && mp[s[idx]].second<=n) 
            pick = 1 + helper(mp, s, m-mp[s[idx]].first, n-mp[s[idx]].second, idx-1, dp);
        notPick = helper(mp, s, m, n, idx-1, dp);
        return dp[m][n][idx] = max(pick, notPick);
    }
    int findMaxForm(vector<string>&s, int m, int n) {
        map<string, pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = getCount(s[i]);
        }
        int len = s.size();
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(len+1, -1)));
        return helper(mp, s, m, n, len-1, dp);
        
    }
};