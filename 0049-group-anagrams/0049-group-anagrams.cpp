class Solution {
public:
    static bool cmp(pair<string,string>a,pair<string,string>b){
        return a.second < b.second;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>v;
        for(int i=0;i<strs.size();i++){
            pair<string,string>p;
            p.first = strs[i];
            sort(strs[i].begin(),strs[i].end());
            p.second = strs[i];
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        vector<vector<string>>ans;
        bool flag = false;
        vector<string>temp;
        for(int i=0;i<v.size();){
            if(!flag){
                flag = true;
                temp.push_back(v[i].first);
                i++;
            }else{
                if(v[i].second == v[i-1].second){
                    temp.push_back(v[i].first);
                    i++;
                }else{
                    ans.push_back(temp);
                    temp.clear();
                    flag = false;
                }
            }
        }
        if(temp.size()!=0)
            ans.push_back(temp);
        return ans;
    }
};