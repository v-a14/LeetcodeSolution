class Solution {
public:
    string customSortString(string order, string s) {
        static map<char, int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }
        auto cmp = [&](char x, char y){
            return mp[x] < mp[y];
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};