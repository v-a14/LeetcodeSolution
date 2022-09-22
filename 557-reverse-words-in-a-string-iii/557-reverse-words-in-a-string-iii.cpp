class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.size();i++){
            int k = i;
            int j = i;
            while(k<s.size() && s[k]!=' '){
                k++;
            }
            int temp = k;
            k--;
            while(j<k){
                swap(s[j++], s[k--]);
            }
            i = temp;
        }
        return s;
        
    }
};