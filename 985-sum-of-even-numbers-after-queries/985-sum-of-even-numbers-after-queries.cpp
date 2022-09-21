class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int oddSum = 0, evenSum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) evenSum += nums[i];
            else oddSum += nums[i];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int val = queries[i][0];
            int index = queries[i][1];
            if(val%2==0){
                if(nums[index]%2==0){
                    evenSum -= nums[index];
                    nums[index] += val;
                    evenSum += nums[index];
                }else{
                    oddSum -= nums[index];
                    nums[index] += val;
                    oddSum += nums[index];
                }
            }else{
                if(nums[index]%2==0){
                    evenSum -= nums[index];
                    nums[index] += val;
                    oddSum += nums[index];
                }else{
                    oddSum -= nums[index];
                    nums[index] += val;
                    evenSum += nums[index];
                }
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};