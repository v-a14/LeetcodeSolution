class Solution {
public:
    map<int,vector<pair<int,int>>> initialize(){
        map<int, vector<pair<int,int>>>mp;
        mp[1] = {{0,-1},{0,1}};
        mp[2] = {{1,0},{-1,0}};
        mp[3] = {{0,-1},{1,0}};
        mp[4] = {{1,0},{0,1}};
        mp[5] = {{0,-1},{-1,0}};
        mp[6] = {{0,1},{-1,0}};
        return mp;
    }
    bool helper(vector<vector<int>>&grid, vector<vector<bool>>&vis, int x, int y, map<int,vector<pair<int,int>>>&mp){
        if(x == grid.size()-1 && y==grid[0].size()-1) return true;
        vis[x][y] = true;
        for(auto it:mp[grid[x][y]]){
            int newX = it.first + x;
            int newY = it.second + y;
            if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && !vis[newX][newY]){
                bool flag = false;
                for(auto it1:mp[grid[newX][newY]]){
                    if(it1.first == -it.first && it1.second == -it.second){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    if(helper(grid, vis, newX, newY, mp)) return true;
                }
            } 
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        map<int,vector<pair<int,int>>>mp = initialize();
        return helper(grid, vis, 0, 0, mp);
        
    }
};