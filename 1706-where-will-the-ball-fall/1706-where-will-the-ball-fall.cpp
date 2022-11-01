class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // mXn grid 
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m, -1);
        for(int j=0;j<m;j++){
            // ab yha se har ball ke liye check krenge 
            int tempJ = j;
            int i = 0;
            while(i<n && tempJ>=0 && tempJ<m){
                if(grid[i][tempJ] == 1){
                    if(tempJ+1<m){
                       if(grid[i][tempJ+1]==-1){
                        break;
                       }
                    }else{
                        break;
                    }
                    tempJ += 1;
                    i++;
                    continue;
                }
                if(grid[i][tempJ]==-1){
                    if(tempJ-1>=0){
                        if(grid[i][tempJ-1]==1){
                        break;
                       }
                    }else{
                        break;
                    }
                    i++;
                    tempJ-=1;
                    continue;
                }
                
            }
            if(i==n){
                ans[j] = tempJ;
            }
        }
        return ans;
    }
};