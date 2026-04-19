class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m-1;
        int temp = -1;
        while (l<=r){
            int mid = (l+r)/2;
            if (mid==l){
                temp=mid;
                break;
            } 
            if (matrix[mid][0]<target) l = mid+1;
            else if (matrix[mid][0]>target) r = mid - 1;
            else return true;
        }
        if (temp==-1) return false;
        l=0;
        r=n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (matrix[temp][mid]<target) l=mid+1;
            else if (matrix[temp][mid]>target) r=mid-1;
            else return true;
        }
        return false;
    }
};
