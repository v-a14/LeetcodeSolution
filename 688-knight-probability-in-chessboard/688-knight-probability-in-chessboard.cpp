class Solution {
public:
    vector<int>dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int>dy = {1, -1, 2, -2, 2, -2, 1, -1};
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>>dis(n, vector<double>(n, 0.0));
        dis[row][col] = 1.0;
        queue<pair<int,int>>q;
        q.push({row, col});
        while(!q.empty() && k-->0){
            int len = q.size();
            vector<vector<double>>tempDis(n, vector<double>(n, 0.0));
            set<pair<int,int>>s;
            for(int j=0;j<len;j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<8;i++){
                    int currX = dx[i] + x;
                    int currY = dy[i] + y;
                    if(currX>=0 && currX<n && currY>=0 && currY<n){
                        tempDis[currX][currY] += (dis[x][y])/8.0;
                        if(s.find({currX,currY}) != s.end()) continue;
                        q.push({currX, currY});
                        s.insert({currX, currY});
                    }
                }
            }
            dis = tempDis;
        }
        double ans = 0.0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            ans += dis[x][y];
            q.pop();
        }
        return ans;
    }
};