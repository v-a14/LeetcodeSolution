class UndergroundSystem {
public:
    map<pair<string,string>, pair<double, int>>mp;
    map<int, pair<string,int>>mpInput;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mpInput[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>p = mpInput[id];
        int newTime = t - p.second;
        double oldTime = 0.0;
        int count = 0;
        if(mp.find({p.first, stationName})!=mp.end()){
            oldTime = mp[{p.first, stationName}].first;
            count = mp[{p.first, stationName}].second;
        }
        double val = (oldTime*count + newTime)/(double)(count+1);
        mp[{p.first, stationName}] = {val, count+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[{startStation, endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */