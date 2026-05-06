class Solution {
long long search(int r, int c,vector<vector<int>>& points, vector<vector<long long>>& dp){
    int m = points.size();
    int n = points[0].size();
    if (r==m-1) return (long long)points[r][c];
    if (dp[r][c]!=-1) return dp[r][c];
    long long score = INT_MIN;
    for (int i=0;i<n;i++){
        score = max(score,(points[r][c] + search(r+1,i,points,dp) - abs(i-c)));
    }
    dp[r][c] = score;
    return dp[r][c];
}

public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        long long score = INT_MIN;
        for (int i=0;i<n;i++){
            dp[0][i] = search(0,i,points,dp);
            score = max(score,dp[0][i]);
        }
        return score;

    }
};