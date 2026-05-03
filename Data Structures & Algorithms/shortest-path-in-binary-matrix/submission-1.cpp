class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({0,0});
        grid[0][0] = 1;
        int path = 1;

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

        while (!q.empty()){
            int s = q.size();
            for (int i=0;i<s;i++){
                auto [x,y] = q.front();
                q.pop();

                if (x==n-1 && y==n-1) return path;

                for (auto &d: dir){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            path++;

        }
        return -1;
    }
};