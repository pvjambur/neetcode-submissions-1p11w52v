class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int take = jobs[i][2];

            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) take += dp[idx];

            dp[i] = max(dp[i - 1], take);
        }

        return dp[n - 1];
    }
};