class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n, vector<string>& board,
               vector<int>& col, vector<int>& diag, vector<int>& anti) {
        
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag[row + c] || anti[row - c + n - 1])
                continue;

          
            board[row][c] = 'Q';
            col[c] = diag[row + c] = anti[row - c + n - 1] = 1;

            solve(row + 1, n, board, col, diag, anti);

  
            board[row][c] = '.';
            col[c] = diag[row + c] = anti[row - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0), diag(2*n, 0), anti(2*n, 0);

        solve(0, n, board, col, diag, anti);
        return ans;
    }
};