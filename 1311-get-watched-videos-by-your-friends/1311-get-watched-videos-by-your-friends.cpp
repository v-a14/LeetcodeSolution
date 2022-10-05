class Solution {
public:
    static bool cmp(pair<string,int>&x, pair<string,int>&y){
        if(x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int>q;
        q.push(id);
        int n = friends.size();
        vector<bool>vis(n, false);
        vis[id] = true;
        while(level && !q.empty()){
            int len = q.size();
            level--;
            for(int i=0;i<len;i++){
                int node = q.front();
                q.pop();
                for(auto it:friends[node]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        map<string,int>mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:watchedVideos[node]){
                mp[it]++;
            }
        }
        vector<pair<string,int>>v;
        for(auto it:mp){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), cmp);
        vector<string>ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};