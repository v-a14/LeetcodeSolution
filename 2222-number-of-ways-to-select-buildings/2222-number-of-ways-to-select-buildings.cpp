class Solution {
public:
    long long helper(string s, int idx, int prev, int count, vector<vector<vector<long long>>>&dp){
        if(count == 0) return 1;
        if(idx == s.size()) return 0;
        if(dp[idx][prev][count]!=-1) return dp[idx][prev][count];
        long long pick = 0, notPick = 0;
        if(s[idx]-'0'!=prev){
            pick = helper(s, idx+1, s[idx]-'0', count-1, dp);
        }
        notPick = helper(s, idx+1, prev, count, dp);
        return dp[idx][prev][count] = pick + notPick;
        
    }
    long long numberOfWays(string s) {
vector<int> count(2, 0);
        
        // order[0] = current number of pair (0, 1) in order
        // order[1] = current number of pair (1, 0) in order
        vector<long long> order(2, 0);
        long long ans = 0;
        for (auto c: s) {
            
            // update counting number
            count[c - '0']++;
            
            // order[0] will be added by number of '1'
            // order[1] will be added by number of '0'
            order[c - '0'] += count[1 - (c - '0')];
            
            // current total triple will be added by order[0] if current character is '1'
            // current total triple will be added by order[1] if current character is '0'
            ans += order[1 - (c - '0')];
        }
        return ans;
    }
};