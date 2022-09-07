class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int n,m;
    void bfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int x, int y){
        queue<pair<int,int>>q;
        q.push({x, y});
        vis[x][y] = true;
        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int tempX = currX + dx[i];
                int tempY = currY + dy[i];
                if(tempX>=0 && tempX<n && tempY>=0 && tempY<m && grid[tempX][tempY] == '1' && vis[tempX][tempY] == false){
                    q.push({tempX, tempY});
                    vis[tempX][tempY] = true;
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    count++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};