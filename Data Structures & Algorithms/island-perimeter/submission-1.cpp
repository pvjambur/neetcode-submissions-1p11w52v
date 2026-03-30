class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if (r<0 || c<0 || r>=m || c>=n) return 1;
        else if (grid[r][c]==0) return 1;
        else if (grid[r][c]==2) return 0;
        grid[r][c]=2;
        int area = 0;
        for (auto &d: dir){
            area+=dfs(r+d[0],c+d[1],grid);
        }
        return area;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1)
                    return dfs(i,j,grid);
            }
        }
        return -1;
    }
};