class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string &s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void helper(string s, int idx, vector<string>&curr){
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }
        string temp;
        for(int i=idx;i<s.size();i++){
            temp += s[i];
            if(isPalindrome(temp)){
                curr.push_back(temp);
                helper(s, i+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        helper(s, 0, curr);
        return ans;
    }
};