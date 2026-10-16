class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 0;

        for (char c : s) {
            int x = c-'a';
            int best = 0;

            for (int j = max(0, x-k); j <= min(25, x+k); j++) {
                best = max(best, dp[j]);
            }

            dp[x] = best + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};