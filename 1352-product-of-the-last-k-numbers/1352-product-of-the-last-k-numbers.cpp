class ProductOfNumbers {
public:
    vector<int>arr;
    int currSize = 0;
    set<int>s;
    ProductOfNumbers() {
        arr.push_back(1);
    }
    void add(int num) {
        currSize++;
        if(num==0){
            arr.push_back(1);
            s.insert(currSize);
            return;
        } else arr.push_back(num);
        arr[currSize] *= arr[currSize-1];
    }
    
    int getProduct(int k) {
        // cout << currSize - k << endl;
        // for(auto it:s) cout << it << " ";
        // cout << endl;
        auto it = s.upper_bound(currSize-k);
        if(it!=s.end()) return 0;
        else return arr[currSize]/arr[currSize-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */