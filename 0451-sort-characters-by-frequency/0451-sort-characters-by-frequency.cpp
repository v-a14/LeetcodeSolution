class Solution {
public:
    static bool cmp(pair<char,int>&x, pair<char,int>&y){
        return x.second > y.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s) mp[it]++;
        vector<pair<char,int>>v;
        for(auto it:mp){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), cmp);
        string ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++){
                ans += v[i].first;
            }
        }
        return ans;
        
    }
};