class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});   // {effort,row,col}

        vector<vector<int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int effort = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == m - 1 && c == n - 1)
                return effort;

            if (effort > dist[r][c])
                continue;

            for (auto &d : dir) {

                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int edge = abs(heights[r][c] - heights[nr][nc]);

                int newEffort = max(effort, edge);

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};