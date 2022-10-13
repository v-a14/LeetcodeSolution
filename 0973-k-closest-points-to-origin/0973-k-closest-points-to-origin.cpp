class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>>pq;
        for(int i=0;i<points.size();i++){
            double x = points[i][0];
            double y = points[i][1];
            double dis = (double)(sqrt(pow(x, 2) + pow(y, 2)));
            pq.push({dis, x, y});
        }
        vector<vector<int>>ans;
        while(k--){
            int x = pq.top()[1];
            int y = pq.top()[2];
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};