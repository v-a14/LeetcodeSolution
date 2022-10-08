class FindSumPairs {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    vector<int>arr;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            mp[i] = nums2[i];
            mp1[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            arr.push_back(nums1[i]);
        }
    }
    void add(int index, int val) {
        int temp = mp[index];
        mp[index] += val;
        mp1[temp]--;
        mp1[temp+val]++;
    }
    
    int count(int sum){
        int count = 0;
        for(int i=0;i<arr.size();i++){
            count += mp1[sum-arr[i]];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */