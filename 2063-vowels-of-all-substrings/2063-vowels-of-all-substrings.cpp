class Solution {
public:
    bool helper(char x){
        if(x == 'a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
        return false;
    }
    long long countVowels(string word) {
        long long count = 0;
        int n = word.size();
        for(long long i=0;i<word.size();i++){
            if(helper(word[i])) count += (i+1)*(n-i);
        }
        return count;
    }
};