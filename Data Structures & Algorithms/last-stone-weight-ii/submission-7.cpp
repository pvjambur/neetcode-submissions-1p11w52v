class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int s : stones) sum += s;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int s : stones) {
            for (int j = target; j >= s; j--) {
                dp[j] = dp[j] || dp[j - s];
            }
        }

        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }

        return 0;
    }
};