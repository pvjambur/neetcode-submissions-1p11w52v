class Solution {
private:
    int search(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& triangle){
        if (r>=triangle.size()) return 0;
        if (dp[r][c]!=-1) return dp[r][c];
        else dp[r][c] = triangle[r][c] + min(search(r+1,c,dp,triangle),search(r+1,c+1,dp,triangle));
        return dp[r][c];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = m;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return search(0,0,dp,triangle);
    }
};