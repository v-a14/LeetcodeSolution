class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>temp;
        for(int i=0;i<words.size();i++){
            vector<int>arr(26, 0);
            for(auto it:words[i]) arr[it-'a']++;
            for(auto it:arr){
                if(it>0){
                    temp.push_back(it);
                    break;
                }
            }
        }
        sort(temp.begin(), temp.end());
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            vector<int>arr(26, 0);
            for(auto it:queries[i]){
                arr[it-'a']++;
            }
            int val;
            for(auto it:arr){
                if(it > 0){
                    val = it;
                    break;
                } 
            }
            auto it = temp.end() - upper_bound(temp.begin(), temp.end(), val);
            ans.push_back(it);
        }
        return ans;
    }
};