class Solution {
private:
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid, int& fresh, int& time){
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()){
            int size = q.size();
            bool isrotten = false;
            
            for (int i=0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();    
                for (auto &d: dir){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        isrotten = true;
                        fresh--;
                    }
                }
            }
            if (isrotten) time++;
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==2) q.push({i,j});
                else if (grid[i][j]==1) fresh++;
            }
        }

        if (fresh==0) return 0;

        bfs(q,grid,fresh,time);

        if (fresh==0) return time;
        return -1;
    }
};
