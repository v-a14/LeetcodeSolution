class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>indegree(100001, 0);
        set<int>s;
        for(int i=0;i<matches.size();i++){
            indegree[matches[i][1]]++;
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
        }
        vector<vector<int>>ans(2);
        vector<int>winn, los;
        int val = *(s.rbegin());
        for(auto i:s){
            if(indegree[i] == 0){
                winn.push_back(i);
            }
           if(indegree[i] == 1){
                los.push_back(i);
            }
        }
        ans[0] = winn;
        ans[1] = los;
        return ans;
        
    }
};