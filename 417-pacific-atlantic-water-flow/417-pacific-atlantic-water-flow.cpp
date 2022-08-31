class Solution {
public:
    int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
void bfs(vector<vector<int>> &red,queue<pair<int,int>> q,vector<vector<int> > A){
    while(!q.empty()){
        auto xx=q.front().first,yy=q.front().second;
        red[xx][yy]=1;
        for(int i=0;i<4;i++){
            int x=xx+dx[i];
            int y=yy+dy[i];
            if(x<red.size()&&y<red[0].size()&&x>=0&&y>=0&&red[x][y]==0&&A[xx][yy]<=A[x][y]){
                red[x][y]=1;
                q.push({x,y});
            }
        }
        q.pop();
    }
    return;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
      queue<pair<int,int>> q1,q2;
    int n=A.size(),m=A[0].size();
    vector<vector<int>> red(n,vector<int>(m,0)),blue(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        q1.push({0,i});
    }
    for(int j=1;j<n;j++){
        q1.push({j,0});
    }
    for(int i=0;i<m;i++){
        q2.push({n-1,i});
    }
    for(int j=n-2;j>=0;j--){
        q2.push({j,m-1});
    }
    bfs(red,q1,A);
    bfs(blue,q2,A);
    int cnt=0;
        vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(red[i][j]==1&&blue[i][j]==1){ans.push_back({i,j});}
        }
    }
    return ans;  
    }
};