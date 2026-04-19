class Solution {
private:
    void dfs(int time, int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if (r<0 || c<0 || r>=m || c>=n || grid[r][c]==2) return 0;

        grid[r][c] = 2;
        time = max(time,dfs(time+1,r+1,c,grid));
        time = max(time,dfs(time+1,r+1,c,grid));
        time = max(time,dfs(time+1,r+1,c,grid));
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==2){
                    time = dfs(time,i,j,grid);
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;

    }
};
