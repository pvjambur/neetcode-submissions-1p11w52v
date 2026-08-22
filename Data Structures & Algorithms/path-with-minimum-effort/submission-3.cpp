class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dp(m,vector<int>(n,1e7));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0,0});
        dp[0][0] = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!pq.empty()){
            int effort = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if (r==m-1 && c==n-1) return effort;
            for (auto &d: dir){
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr<0 || nc<0 || nr>=m || nc>=n) continue;
                int cur_eff = abs(heights[nr][nc]-heights[r][c]);
                int new_effort = max(effort, cur_eff);
                if (new_effort<dp[nr][nc]){
                    dp[nr][nc] = new_effort;
                    pq.push({new_effort,nr,nc});
                }
            }
        }
        return -1;


    }
};