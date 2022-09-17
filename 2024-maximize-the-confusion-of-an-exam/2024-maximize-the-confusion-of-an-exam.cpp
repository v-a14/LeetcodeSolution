class Solution {
public:
    int helper(string arr, int k, char x){
        int i = 0, j = 0;
        int ans = 0;
        while(j<arr.size()){
            if(arr[j] == x){
                j++;
            }else{
                j++;
                k--;
                while(k<0){
                    if(arr[i]!=x){
                        k++;
                    }
                    i++;
                }
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
        return ans;
    }
};