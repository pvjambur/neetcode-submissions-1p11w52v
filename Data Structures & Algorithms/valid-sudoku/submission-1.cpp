class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows,cols,grids;

        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.') continue;
                int num = board[i][j] - '0';
                int ind = (3*(i/3) + (j/3));
                if (rows[i].count(num) || cols[j].count(num) || grids[ind].count(num)){
                    return false;
                }
                rows[i].insert(num);
                cols[j].insert(num);
                grids[ind].insert(num);
            }
        }

        return true;
    }
};