class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if (r<0 || c<0 || r>=m || c>=n || grid[r][c]==0) return;
        grid[r][c] = 0;
        for (auto &d: dir){
            dfs(r+d[0],c+d[1],grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i=0;i<n;i++){
            if (grid[0][i]==1) dfs(0,i,grid);
            if (grid[m-1][i]) dfs(m-1,i,grid);
        }

        for (int i=0;i<m;i++){
            if (grid[i][0]==1) dfs(i,0,grid);
            if (grid[i][n-1]) dfs(i,n-1,grid);
        }

        int count = 0;

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1) count++;
            }
        }
        return count;
    }
};