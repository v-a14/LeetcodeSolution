class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()){
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }
    int getRandom() {
        int n = s.size();
        int num = rand()%n;
        auto it = s.begin();
        advance(it, num);
        return *(it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */