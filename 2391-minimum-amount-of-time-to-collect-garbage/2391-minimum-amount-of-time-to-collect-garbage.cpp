class Solution {
public:
    int helper(vector<int>&travel, vector<string>&garbage, char x){
        int idx = 0;
        int totalTime = 0;
        int n = travel.size()+1;
        vector<int>prefix(n, 0);
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + travel[i-1];
        }
        bool flag = false;
        for(int i=idx; i<garbage.size();i++){
            for(auto it:garbage[i]){
                if(it == x){
                    idx = i;
                    totalTime++;
                }
            }

        }
        // for(int i=0;i<n;i++) cout << prefix[i] << " ";
        // cout << endl;
        // cout << idx << endl;
        return prefix[idx] + totalTime;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        ans += helper(travel, garbage, 'M') + helper(travel, garbage, 'P') + helper(travel, garbage,'G');
        return ans;
    }
};