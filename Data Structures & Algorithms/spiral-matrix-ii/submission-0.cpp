class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int l = 0, r = n-1, t = 0, b = n-1;
        int num = 1;
        while (num<=n){
            for (int i=l;i<=r;i++){
                grid[t][i] = num++;
            }
            t++;
            for (int i=t;i<=b;i++){
                grid[i][r] = num++;
            }
            r--;
            for (int i=r;i>=l;i--){
                grid[b][i] = num++;
            }
            b--;
            for (int i=b;i>=t;i--){
                grid[i][l] = num++;
            }
            l++;
        }
        if (n%2==1) grid[n/2][n/2] = n*n;
        return grid;
    }
};