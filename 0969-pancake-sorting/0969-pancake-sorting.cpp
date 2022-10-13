class Solution {
public:
    int helper(vector<int>&arr, int x){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == x) return i;
        }
        return 0;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int ele = arr.size();
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int find = helper(arr, ele);
            ans.push_back(find+1);
            reverse(arr.begin(), arr.begin()+find+1);
            ans.push_back(ele);
            reverse(arr.begin(), arr.begin()+ele);
            ele--;
        }
        return ans;
    }
};