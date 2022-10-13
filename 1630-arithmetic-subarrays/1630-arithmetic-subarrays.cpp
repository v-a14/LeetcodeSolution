class Solution {
public:
    bool check(vector<int>&arr){
        if(arr.size() == 1 || arr.size() == 2) return true;
        int diff = arr[1] - arr[0];
        for(int i=2;i<arr.size();i++){
            if(arr[i] - arr[i-1] != diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>ans;
        for(int i=0;i<n;i++){
            int start = l[i];
            int end = r[i];
            vector<int>temp;
            for(int j=start;j<=end;j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            if(check(temp)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};