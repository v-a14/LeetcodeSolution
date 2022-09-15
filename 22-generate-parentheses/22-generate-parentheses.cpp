class Solution {
public:
    vector<string>ans;
    void helper(int leftBracket, int n, string s){
        if(leftBracket>n) return;
        if(n == 0){
            ans.push_back(s);
            return;
        }
        if(leftBracket>0){
            helper(leftBracket-1, n-1, s+')');
            helper(leftBracket+1, n, s+'(');
        }else{
            helper(leftBracket+1, n, s+'(');
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        helper(0, n, s);
        return ans;
    }
};