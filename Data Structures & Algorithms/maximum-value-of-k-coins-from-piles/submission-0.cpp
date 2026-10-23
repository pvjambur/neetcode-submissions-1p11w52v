class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);

        for (auto &p : piles) {
            int n = p.size();

            for (int j = k; j >= 1; j--) {
                int sum = 0;

                for (int x = 1; x <= min(n, j); x++) {
                    sum += p[x - 1];
                    dp[j] = max(dp[j], dp[j - x] + sum);
                }
            }
        }

        return dp[k];
    }
};