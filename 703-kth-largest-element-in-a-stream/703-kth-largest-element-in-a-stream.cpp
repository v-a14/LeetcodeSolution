class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for(auto it:nums){
            pq.push(it);
        }
        while(pq.size()>x) pq.pop();
    }
    int add(int val) {
        if(pq.size()<x) 
            pq.push(val);
        else{
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */