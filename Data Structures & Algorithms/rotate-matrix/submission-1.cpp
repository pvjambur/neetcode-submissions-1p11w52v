class Solution {
private:
    void reverse(vector<int>& row,int s){
        int i=0,j=s-1;
        while(i<j){
            int temp = row[i];
            row[i] = row[j];
            row[j] = temp;
            i++;
            j--;
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();
        for (int i=0;i<s;i++){
            for (int j=i+1;j<s;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i=0;i<s;i++){
            reverse(matrix[i],s);
        }
    }
};
