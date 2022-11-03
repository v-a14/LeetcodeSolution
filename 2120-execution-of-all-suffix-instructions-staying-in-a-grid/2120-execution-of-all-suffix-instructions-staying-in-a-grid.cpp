class Solution {
public:
    int helper(int x, int y, int n, string &s, int idx){
        int count = 0;
        for(int i=idx;i<s.size();i++){
            if(s[i] == 'L') y -= 1;
            if(s[i] == 'R') y += 1;
            if(s[i] == 'U') x -= 1;
            if(s[i] == 'D') x += 1;
            if(x<0 || x>=n || y<0 || y>=n) return count;
            count++;
        }
        return count;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int sz = s.size();
        vector<int>ans(sz);
        for(int i=0;i<s.size();i++){
            ans[i] = helper(startPos[0], startPos[1], n, s, i);
        }
        return ans;
    }
};