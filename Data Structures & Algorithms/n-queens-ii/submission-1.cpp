class Solution {
private:
    bool searchDiag(int r, int c, vector<vector<int>>& grid){
        int n = grid.size();
        int x = r-1, y = c+1;
        while (x>=0 && y<n){
            if (grid[x][y]==1) return true;
            x--;
            y++;
        }
        x = r-1; y = c-1;
        while (x>=0 && y>=0){
            if (grid[x][y]==1) return true;
            x--;
            y--;
        }
        return false;
    }

    int backtrack(int r, vector<vector<int>>& grid, vector<bool>& col){
        int n = grid.size();
        if (r==n) return 1;
        int ways = 0;
        for (int c=0;c<n;c++){
            if (col[c] || searchDiag(r,c,grid)) continue;
            grid[r][c] = 1;
            col[c] = true;
            ways += backtrack(r+1,grid,col);
            grid[r][c] = 0;
            col[c] = false;
        }
        return ways;
    }

public:
    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<bool> col(n,false);
        return backtrack(0,grid,col);
    }
};