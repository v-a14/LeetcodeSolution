class Solution {
public:
    int longestSubarray(vector<int>& s) {
        int i = 0, j = 0;
        int count = 0;
        int ans = 0;
        while(j<s.size()){
            if(s[j] == 0){
                count++;
                while(count>1){
                    if(s[i] == 0) count--;
                    i++;
                }
            }
            j++;
            ans = max(ans, j - i);
        }
        return ans-1;
    }
};