class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, vector<int>& h) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int area = (j - i) * min(h[i], h[j]);
        dp[i][j] = max({
            area,
            solve(i + 1, j, dp, h),
            solve(i, j - 1, dp, h)
        });

        return dp[i][j];
    }

public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, dp, heights);
    }
};
