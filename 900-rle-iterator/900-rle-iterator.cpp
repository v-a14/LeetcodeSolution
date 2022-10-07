class RLEIterator {
public:
    int val = 0;
    int currI = 0;
    vector<int>arr;
    int len = 0;
    RLEIterator(vector<int>& encoding) {
        for(int i=0;i<encoding.size();i++){
            arr.push_back(encoding[i]);
        }
        val = arr[0];
        len = arr.size();
    }
    int next(int n) {
        while(currI<len && n>0){
            if(val >= n){
                val -= n;
                n = 0;
                break;
            }else{
                n -= val;
                currI += 2;
                if(currI>=len) return -1;
                val = arr[currI];
            }
        }
        if(n==0)
            return arr[currI+1];
        else return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */