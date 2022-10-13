class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int x) {
        vector<int>diff;
        int count = 0;
        for(int i=0;i<rocks.size();i++){
            if(capacity[i] - rocks[i] > 0){
                diff.push_back(capacity[i] - rocks[i]);
            }else{
                count++;
            }
        }
        sort(diff.begin(), diff.end());
        for(int i=0;i<diff.size();i++){
            if(x>=diff[i]){
                x -= diff[i];
                count++;
            }
        }
        return count;
    }
};