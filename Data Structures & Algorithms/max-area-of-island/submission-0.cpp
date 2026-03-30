class Solution {
private: 
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=0;
        int area = 1;
        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (auto d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    area++;
                    q.push({nx,ny});
                }
            }
        }
        return area;
    }



public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    area = max(area,bfs(i,j,grid));
                }
            }
        }
        return area;
    }
};