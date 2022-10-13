class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>>mp;
        set<string>s;
        for(int i=0;i<orders.size();i++){
            mp[stoi(orders[i][1])][orders[i][2]]++;
            s.insert(orders[i][2]);
        }
        vector<vector<string>>ans;
        vector<string>temp;
        temp.push_back("Table");
        for(auto it:s){
            temp.push_back(it);
        }
        ans.push_back(temp);
        for(auto it:mp){
            vector<string>temp;
            temp.push_back(to_string(it.first));
            for(int i=1;i<ans[0].size();i++){
                temp.push_back(to_string(it.second[ans[0][i]]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};