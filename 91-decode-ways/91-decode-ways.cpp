class Solution {
public:
    int helper(int i,string s,int n,int *dp){
        if(s[i]=='0')
            return 0;
        if(i==n-1 || i==n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int a = 0, b= 0;
        if(i<n-1){
            int value = (s[i]-'0')*10 + (s[i+1]-'0');
            if(value <= 26){
                a= helper(i+2,s,n,dp);
            }
        }
        b =  helper(i+1,s,n,dp);
        return dp[i] = a+b;
    }
    int numDecodings(string s) {
        int n = s.size();
        int *dp = new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        int value = helper(0,s,s.size(),dp);
        return value;
    }
};