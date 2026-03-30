class Solution {
private:
    int choose(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (r<0 || c<0) return INT_MAX;
        if (dp[r][c]!=-1) return dp[r][c];
        if (r==0 && c==0) return grid[0][0];
        int u = choose(r,c-1,grid,dp);
        int l = choose(r-1,c,grid,dp);
        dp[r][c] = grid[r][c] + min(u,l);
        return dp[r][c];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int minPath = choose(m-1,n-1,grid,dp);
        return minPath;
    }
};