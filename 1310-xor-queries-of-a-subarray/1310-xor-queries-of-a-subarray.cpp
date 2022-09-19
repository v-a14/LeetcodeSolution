class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prefix(n+1, 0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]^arr[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            right++;
            ans.push_back(prefix[right]^prefix[left]);
        }
        return ans;
    }
};