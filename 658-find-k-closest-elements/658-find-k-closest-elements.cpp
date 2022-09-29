class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i;
        int n = arr.size();
        if(j == 0){
            i = 0;
            j = 1;
        }else{
            i = j-1;
        }
        vector<int>ans;
        while(i>=0 && j<n && k-->0){
            int diff1 = abs(x - arr[i]);
            int diff2 = abs(x - arr[j]);
            if(diff1>diff2){
                j++;
            }else{
                if(diff1<=diff2){
                    i--;
                }
            }
        }
        while(j<n && k-->0) j++;
        while(i>=0 && k-->0) i--;
        for(int k=i+1;k<j;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};