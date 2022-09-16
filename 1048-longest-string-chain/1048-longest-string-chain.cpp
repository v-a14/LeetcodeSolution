class Solution {
public:
    bool check(string &x, string &y){
        int n = x.size();
        int m = y.size();
        if(n-m!=1) return false;
        int i = 0, j = 0;
        bool flag = false;
        while(i<n && j<m){
            if(x[i]!=y[j]){
                if(!flag){
                    i++;
                    flag = true;
                    continue;
                }
                else return false;
            }
            i++; j++;
        }
        return true;
    }
    static bool cmp(string &x, string &y){
        return x.size() < y.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n, 1);
        sort(words.begin(), words.end(), cmp);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i], words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};