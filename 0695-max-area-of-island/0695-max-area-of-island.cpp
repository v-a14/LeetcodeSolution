class Solution {
public:
    int n,m;
    vector<int>dx = {1,0,-1,0};
    vector<int>dy = {0,1,0,-1};
    int helper(vector<vector<int>>&grid, vector<vector<bool>>&vis, int x, int y){
        if(x<0 || x>=n || y<0 || y>=m || !grid[x][y] || vis[x][y]) return 0;
        vis[x][y] = true;
        int ans = 0;
        for(int i=0;i<4;i++){
            int tempX = dx[i] + x;
            int tempY = dy[i] + y;
            ans += helper(grid, vis, tempX, tempY);
        }
        return 1 + ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    ans = max(ans, helper(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};