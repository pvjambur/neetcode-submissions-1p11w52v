class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        if (r<0 || c<0 || r>=m || c>=n || board[r][c]=='X' || board[r][c]=='Y') return;
        board[r][c] = 'Y';
        for (auto &d: dir){
            dfs(r+d[0],c+d[1],board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }

        for (int j=1;j<n-1;j++){
            dfs(0,j,board);
            dfs(m-1,j,board);
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};
