class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& arr, vector<int>& persons) {
        vector<int>start, end;
        for(int i=0;i<arr.size();i++){
            start.push_back(arr[i][0]);
            end.push_back(arr[i][1]+1);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int>ans;
        for(int i=0;i<persons.size();i++){
            auto it1 = upper_bound(start.begin(), start.end(), persons[i]) - start.begin();
            auto it2 = upper_bound(end.begin(), end.end(), persons[i]) - end.begin();
            // cout << it1 << " " << it2 << endl;
            it2 = max((int)0, (int)it2);
            it1 = max((int)0, (int)it1);
            ans.push_back(it1 - it2);
        }
        return ans;
    }
};