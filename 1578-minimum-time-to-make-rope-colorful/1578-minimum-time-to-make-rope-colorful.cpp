class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int j = i + 1;
            int sum = neededTime[i];
            int maxVal = neededTime[i];
            while(j<s.size() && s[j] == s[i]){
                sum += neededTime[j];
                maxVal = max(maxVal, neededTime[j]);
                j++;
            }
            i = j - 1;
            ans += (sum-maxVal);
        }
        return ans;
    }
    
};