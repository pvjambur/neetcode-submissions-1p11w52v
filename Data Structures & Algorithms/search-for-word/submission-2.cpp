class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int ind){
        if (ind==word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (r<0 || c<0 || r>=m || c>=n || board[r][c]!=word[ind]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool val = false;
        for (auto &d: dir){
            val = val || dfs(r + d[0],c + d[1],board,word,ind+1);
        }
        board[r][c] = temp;
        return val;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (dfs(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};
