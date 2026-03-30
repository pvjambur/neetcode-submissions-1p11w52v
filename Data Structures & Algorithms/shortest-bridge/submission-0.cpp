class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1)
                return;

            grid[r][c] = 2;
            q.push({r, c});

            for (auto [dr, dc] : dir) {
                dfs(r + dr, c + dc);
            }
        };

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                        if (grid[nr][nc] == 1) {
                            return steps;
                        }
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};