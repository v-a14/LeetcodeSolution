class Solution {
public:
    int helper(vector<vector<int>>&clips, int time, int idx, int endTime, vector<vector<int>>&dp){
        if(idx == clips.size()) return 1e9;
        if(clips[idx][0]>endTime) return 1e9;
        if(clips[idx][1]>=time){
            return 1;
        }
        if(dp[idx][endTime]!=-1) return dp[idx][endTime];
        int pick = 1e9, notPick = 1e9;
        if(clips[idx][0]<=endTime){
            pick = 1 + helper(clips, time, idx+1, clips[idx][1], dp);
        }
        notPick = helper(clips, time, idx+1, endTime, dp);
        return dp[idx][endTime] = min(pick, notPick);
    }
    static bool cmp(vector<int>&x, vector<int>&y){
        return x[0] < y[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), cmp);
        vector<vector<int>>dp(101, vector<int>(101, -1));
        int ans = helper(clips, time, 0, 0, dp);
        return ans>=1e9 ? -1 : ans;
    }
};