class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void check (vector<vector<int>>& grid, int r, int c){
        queue<vector<int>> q;
        q.push({r,c,0});
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int val  = q.front()[2];
            q.pop();

            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]==-1 || grid[nx][ny]==0) continue;
                else{
                    if (grid[nx][ny]>(val+1)){
                        grid[nx][ny] = val+1;
                        q.push({nx,ny,val+1});
                    }
                }
            }
        }
    }

public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0){
                    check(grid,i,j);
                }
            }
        }
    }
};
