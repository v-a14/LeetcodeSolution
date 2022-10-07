class AuthenticationManager {
public:
    int ttl;
    unordered_map<string,int>mp;
    set<int>s;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
        s.insert(0);
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = (currentTime + ttl-1);
        s.insert(mp[tokenId]);
        return;
    }
    
    void renew(string tokenId, int currentTime) {
        int val = mp[tokenId];
        if(val >= currentTime){
            s.erase(mp[tokenId]);
            mp[tokenId] = currentTime + ttl-1;
            s.insert(mp[tokenId]);
        }
        return;
    }
    int countUnexpiredTokens(int currentTime) {
        // if(s.size() == 0) return 0;
        // int val;
        int val = distance(s.lower_bound(currentTime), s.end());
        // cout << val << endl;
        return val;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */