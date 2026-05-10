class Solution {
private:
    vector<vector<int>> dir = {{1,0},{0,1}};
    int search(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if (r<0 || c<0 || r>=m || c>=n || grid[r][c]==1) return 0;
        if (r==m-1 && c==n-1) return 1;
        if (dp[r][c]!=-1) return dp[r][c];
        grid[r][c] = 1;
        int paths = 0;
        if (r!=m-1 || c!=n-1){
            for (auto &d: dir){
                paths += search(r+d[0],c+d[1],grid,dp);
            }
        }
        else if (r==m-1){
            paths += search(r,c+1,grid,dp);
        }
        else if (c==n-1){
            paths += search(r+1,c,grid,dp);
        }
        dp[r][c] = paths;
        grid[r][c] = 0;
        return dp[r][c];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if (obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;
        if (m==1 && n==1) return 1;

        return search(0,0,obstacleGrid,dp);
    }
};