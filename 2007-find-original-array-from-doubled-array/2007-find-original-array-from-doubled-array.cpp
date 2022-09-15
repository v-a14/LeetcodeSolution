class Solution {
public:
    vector<int> findOriginalArray(vector<int>&arr) {
        vector<int>ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        map<int,int>mp;
        bool flag = true;
        for(auto it:arr) mp[it]++;
        for(int i=0;i<n;i++){
            int val1 = 2*arr[i];
            int val2 = arr[i];
            if(mp[val2] == 0){
                continue;
            }
            mp[val2]--;
            if(mp[val1] == 0){
                flag = false;
                break;
            }
            ans.push_back(val2);
            mp[val1]--;

        }
        if(!flag) return {};
        return ans;
    }
};