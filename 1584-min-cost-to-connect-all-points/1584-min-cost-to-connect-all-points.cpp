class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>, int>mp;
        set<pair<int,int>>s;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            s.insert({x,y});
            mp[{x,y}] = INT_MAX;
        }
        int startx = points[0][0];
        int starty = points[0][1];
        int n = points.size();
        mp[{startx,starty}] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, startx, starty});
        while(!pq.empty()){
            int currX = pq.top()[1];
            int currY = pq.top()[2];
            int idx = pq.top()[3];
            s.erase({currX, currY});
            pq.pop();
            for(auto it:s){
                int x = it.first;
                int y = it.second;
                int cost = abs(currX-x) + abs(currY-y);
                if(mp[{x,y}] > cost){
                    mp[{x,y}] = cost;
                    pq.push({cost, x, y});
                }
            }
        }
        int sum = 0;
        for(auto it:mp){
            sum += it.second;
        }
        return sum;
    }
};