class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    grid[i][j]=-1;
                    q.push({i,j});
                }
                else{
                    grid[i][j] = 1e9;
                }
            }
        }
        int max_dist = -1;
        int dist = 1;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [r,c] = q.front();
                q.pop();
                for (auto &d: dir){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr<0 || nc<0 || nr>=m || nc>=n || dist>=grid[nr][nc]) continue;
                    grid[nr][nc] = dist;
                    q.push({nr,nc});
                    max_dist = max(max_dist,grid[nr][nc]);
                }
            }
            dist++;
        }
        return max_dist;
    }
};
