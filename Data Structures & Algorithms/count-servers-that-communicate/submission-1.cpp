class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> rows,cols;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    rows[i]++;
                }
            }
        }

        for (int j=0;j<n;j++){
            for (int i=0;i<m;i++){
                if (grid[i][j]==1){
                    cols[j]++;
                }
            }
        }

        int count = 0;

        for (int i=0;i<m;i++){
            if (!rows.count(i) || rows[i]<2) continue;
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    grid[i][j]=2;
                    count++;
                }
            }
        }

        for (int j=0;j<n;j++){
            if (!cols.count(j) || cols[j]<2) continue;
            for (int i=0;i<m;i++){
                if (grid[i][j]==1){
                    grid[i][j]=2;
                    count++;
                }
            }
        }
        return count;
    }
};