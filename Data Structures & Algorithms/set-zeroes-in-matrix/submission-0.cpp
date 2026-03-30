class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r;
        unordered_set<int> c;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for (int x: r){
            for (int i=0;i<n;i++){
                matrix[x][i]=0;
            }
        }
        for (int x: c){
            for (int i=0;i<m;i++){
                matrix[i][x]=0;
            }
        }
    }
};
