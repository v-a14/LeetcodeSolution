class StockPrice {
public:
    map<int,int>mp1;
    map<int,int>mp;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end()){
            mp1[mp[timestamp]]--;
            if(mp1[mp[timestamp]] == 0){
                mp1.erase(mp[timestamp]);
            }
        }
        mp[timestamp] = price;
        mp1[mp[timestamp]]++;
        return;
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return mp1.rbegin()->first;
    }
    
    int minimum() {
        return mp1.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */