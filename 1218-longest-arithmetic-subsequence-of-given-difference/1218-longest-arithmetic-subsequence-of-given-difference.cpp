class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int,int>mp;
        mp[arr[0]] = 0;
        vector<int>dis(n, 1);
        for(int i=1;i<n;i++){
            int val = arr[i] - difference;
            if(mp.find(val)!=mp.end()){
                int idx = mp[val];
                if(dis[i]<dis[idx] + 1){
                    dis[i] = dis[idx]+1;
                    mp[arr[i]] = i;
                }
            }
            if(mp.find(arr[i])!=mp.end()){
                if(dis[mp[arr[i]]] < dis[i]){
                    mp[arr[i]] = i;
                }
            }else{
                mp[arr[i]] = i;
            }
        }
        int ans = 0;
        for(auto it:dis) ans = max(ans, it);
        return ans;
    }
};