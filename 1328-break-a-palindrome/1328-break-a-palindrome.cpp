class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size() == 1) return "";
        int i = 0;
        for(i=0;i<s.size()/2;i++){
            if(s[i]!='a'){
                s[i] = 'a';
                return s;
            }
        }
        int n = s.size();
        s[n-1] = 'b';
        return s;
    }
};