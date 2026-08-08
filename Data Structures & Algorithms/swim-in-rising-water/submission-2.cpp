class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()){
            auto [time, p] = pq.top();
            auto [x, y] = p;
            pq.pop();

            if (vis[x][y]) continue;
            vis[x][y] = true;

            if (x == n-1 && y == n-1) return time;

            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;

                int newTime = max(time, grid[nx][ny]);

                if (newTime < dist[nx][ny]){
                    dist[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }

        return dist[n-1][n-1];
    }
};