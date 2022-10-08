class NumberContainers {
public:
    // number vs index of maps 
    map<int,set<int>>mp1;
    // index vs number map
    map<int,int>mp2; 
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)!=mp2.end()){
            int val = mp2[index];
            mp1[val].erase(index);
            mp2[index] = number;
            mp1[number].insert(index);
        }else{
            mp2[index] = number;
            mp1[number].insert(index);
        }
    }
    int find(int number) {
        if(mp1.find(number) == mp1.end() || mp1[number].size()==0) return -1;
        return *(mp1[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */