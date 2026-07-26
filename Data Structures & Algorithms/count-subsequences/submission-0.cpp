class Solution {
public:
    int n, m;
    vector<vector<long long>> dp;

    long long dfs(int i, int j, string &s, string &t) {

        if (j == m)
            return 1;

        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = dfs(i + 1, j, s, t);

        if (s[i] == t[j])
            ans += dfs(i + 1, j + 1, s, t);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {

        n = s.size();
        m = t.size();

        dp.assign(n, vector<long long>(m, -1));

        return dfs(0, 0, s, t);
    }
};