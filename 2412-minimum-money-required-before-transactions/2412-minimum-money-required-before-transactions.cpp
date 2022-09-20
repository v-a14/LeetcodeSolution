class Solution {
public:
    static bool cmp(vector<int>&x, vector<int>&y){
        if(x[1] == y[1]) 
            return x[0] > y[0];
        return x[1] < y[1];
    }
    static bool cmp1(vector<int>&x, vector<int>&y){
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0]>y[0];
    }
    long long minimumMoney(vector<vector<int>>& arr) {
        vector<vector<int>>temp, temp1;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0] > arr[i][1]) temp.push_back(arr[i]);
            else temp1.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end(), cmp);
        sort(temp1.begin(), temp1.end(), cmp1);
        long long maxValue = 0;
        long long  currValue = 0;
        for(int i=0;i<temp.size();i++){
            currValue += temp[i][0];
            maxValue = max(maxValue, currValue);
            currValue -= temp[i][1];
        }
        for(int i=0;i<temp1.size();i++){
            currValue += temp1[i][0];
            maxValue = max(maxValue, currValue);
            currValue -= temp1[i][1];
        }
        return maxValue;
    }
};