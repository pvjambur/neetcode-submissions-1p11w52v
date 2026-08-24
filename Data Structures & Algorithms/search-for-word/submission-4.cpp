class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int r, int c, vector<vector<char>>& board, string& word, int ind){
        int m = board.size();
        int n = board[0].size();
        if (r<0 || c<0 || r>=m || c>=n || board[r][c]=='.' || board[r][c]!=word[ind]) return false;
        int k = word.size();
        if (ind==k-1) return true;
        char temp = board[r][c];
        board[r][c] = '.';
        for (auto &d: dir){
            int nr = r + d[0];
            int nc = c + d[1];
            if (dfs(nr,nc,board,word,ind+1)){
                board[r][c] = temp;
                return true;
            }
        }
        board[r][c] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]==word[0] && dfs(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};
