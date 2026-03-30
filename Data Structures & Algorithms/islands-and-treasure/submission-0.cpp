class Solution {      

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n){
                    if (grid[nx][ny]==INT_MAX){
                        grid[nx][ny] = min(grid[nx][ny],1+grid[x][y]);
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
};
