class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int n,m;
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int x, int y){
        if(x<0 || y<0 || x>=n|| y>=m || vis[x][y] || grid[x][y]!='1') return;
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            dfs(grid, vis, tempX, tempY);
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
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};