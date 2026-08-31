class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid.push_back(matrix[0]);
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=1;i<m;i++){
            vector<int> temp(n,0);
            for (int j=0;j<n;j++){
                temp[j] = grid[i-1][j] + matrix[i][j]; 
            }
            grid.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        bool flag = false;
        if (row1!=0) flag = true;
        for (int i=col1;i<=col2;i++){
            sum += grid[row2][i];
            if (flag) sum-=grid[row1-1][i];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */