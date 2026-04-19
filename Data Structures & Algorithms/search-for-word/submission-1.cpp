class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool bfs(int r, int c, vector<vector<char>>& board, string word){
        int m = board.size();
        vector<vector<char>> temp_board = board;
        int n = board[0].size();
        int k = word.size();
        queue<pair<int,int>> q;
        q.push({r,c});
        int ind=1;
        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n && ind<k && temp_board[nx][ny]!='0' && temp_board[nx][ny]==word[ind]){
                    ind++;
                    temp_board[nx][ny] = '0';
                    q.push({nx,ny});
                    if (ind==k) return true;
                }
            }
        }
        if (ind>=k) return true;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]==word[0]){
                    if (word.size()==1) return true;
                    if (bfs(i,j,board,word)) return true;
                }
            }
        }
        return false;
    }
};
