class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        if (r<0 || c<0 || r>=m || c>=n || board[r][c] != 'O') return;
        board[r][c]='#';

        for (auto &d: dir){
            dfs(r+d[0],c+d[1],board);
        }
    }


public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            if (board[i][0]=='O') dfs(i,0,board);
            if (board[i][n-1]=='O') dfs(i,n-1,board);
        }
        for (int j=0;j<n;j++){
            if (board[0][j]=='O') dfs(0,j,board);
            if (board[m-1][j]=='O') dfs(n-1,j,board);
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]=='#') board[i][j]='O';
                else if (board[i][j]=='O') board[i][j]='X';
            }
        }

        
    }
};
