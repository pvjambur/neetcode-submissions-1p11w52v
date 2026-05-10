class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if (dp[r][c] != -1) return dp[r][c];
        int paths = 1;
        for (auto &d: dir){
            int nr = r+d[0];
            int nc = c+d[1];
            if (nr<0 || nc<0 || nr>=m || nc>=n) continue;
            if (grid[nr][nc] <= grid[r][c]) continue;
            paths = max(paths, 1+dfs(nr,nc,grid,dp));
        }
        dp[r][c] = paths;
        return dp[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int path = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                path = max(path,dfs(i,j,matrix,dp));
            }
        }
        return path;
    }
};