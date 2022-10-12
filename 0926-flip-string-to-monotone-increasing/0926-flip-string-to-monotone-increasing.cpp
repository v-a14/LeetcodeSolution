class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int>prefix(n+1, 0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + (s[i-1] - '0');
        }
        int ans = 1e9;
        for(int i=0;i<n;i++){
            ans = min(ans, prefix[i] + (n-i-1) - (prefix[n] - prefix[i+1]));
        }
        return ans;
    }
};