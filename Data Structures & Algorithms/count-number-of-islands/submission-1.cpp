class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx>=0 && ny>=0 && nx<=m-1 && ny<=n-1 && grid[nx][ny]=='1'){
                    grid[nx][ny]='0';
                    q.push({nx,ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
