class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int count = 0;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()){
                mp[temp]--;
                if(mp[temp] == 0) mp.erase(temp);
                count += 4;
            }else{
                mp[words[i]]++;
            }
        }
        for(auto it:mp){
            string temp = it.first;
            reverse(temp.begin(), temp.end());
            if(temp == it.first){
                count += 2;
                break;
            }
        }
        return count;
    }
};