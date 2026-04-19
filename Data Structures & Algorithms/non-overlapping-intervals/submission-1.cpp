class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int count=0;
        for (int i=1;i<n;i++){
            if (res.back()[1]>intervals[i][0] || (res.back()[0]==intervals[i][0] && res.back()[1]!=intervals[i][1]) || (res.back()[1]==intervals[i][1] && res.back()[0]!=intervals[i][0])){
                count++;
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return count;
    }
};
