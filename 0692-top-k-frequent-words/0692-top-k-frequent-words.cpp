class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto it:words) mp[it]++;
        auto cmp = [&](string x, string y){
            if(mp[x] == mp[y]) return x < y;
            else return mp[x] > mp[y];
        };
        sort(words.begin(), words.end(), cmp);
        vector<string>ans;
        for(int i=0;i<words.size() && k--; i++){
            string x = words[i];
            int j = i;
            ans.push_back(x);
            while(j<words.size() && x == words[j]){
                j++;
            }
            i = j - 1;
        }
        return ans;
    }
};