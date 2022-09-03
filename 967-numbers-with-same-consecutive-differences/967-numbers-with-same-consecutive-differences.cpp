#define ll long long 
class Solution {
public:
    void dfs(vector<int>adj[], ll num, int i, unordered_set<int>&s, vector<int>&ans, int n){
        if(n==0){
            ans.push_back(num);
            return;
        }
        for(auto it:adj[i]){
            int currNum = num*10 + it;
            // if(s.find(currNum)==s.end()){
                // s.insert(currNum);
                dfs(adj, currNum, it, s, ans, n-1);
            
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>adj[10];
        for(int i=0;i<=9;i++){
            if(k==0){
                adj[i].push_back(i);
                continue;
            }
            if(i+k<=9) adj[i].push_back(i+k);
            if(i-k>=0) adj[i].push_back(i-k);
        }
        vector<int>ans;
        unordered_set<int>s;
        for(int i=1;i<=9;i++){
            ll num = i;
            dfs(adj, num , i, s, ans, n-1);
        }
        return ans;
    }
};