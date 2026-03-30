class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for (int r = n-2; r >= 0; r--) {
            for (int c = 0; c <= r; c++) {
                triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]);
            }
        }

        return triangle[0][0];
    }
};