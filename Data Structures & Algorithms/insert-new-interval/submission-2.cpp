class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if (n==0){
            res.push_back(newInterval);
            return res;
        }
        if (newInterval[0]<=intervals[0][0]){
            res.push_back(newInterval);
            for (int i=0;i<intervals.size();i++){
                if (res.back()[1]>=intervals[i][0] && res.back()[0]<intervals[i][1]){
                    res.back()[1] = max(res.back()[1],intervals[i][1]);
                    res.back()[0] = min(res.back()[0],intervals[i][0]);
                }
                else{
                    res.push_back(intervals[i]);
                }
            }
        }
        else{
            res.push_back(intervals[0]);
            if (intervals.size()==1){
                if (res.back()[1]>=newInterval[0] && res.back()[0]<newInterval[1]){
                    res.back()[1] = max(res.back()[1],newInterval[1]);
                    res.back()[0] = min(res.back()[0],newInterval[0]);
                }
                else{
                    res.push_back(newInterval);
                }
                return res;
            }
            for (int i=1;i<intervals.size();i++){
                if (newInterval[0]<=intervals[i][0]){
                    if (res.back()[1]>=newInterval[0] && res.back()[0]<newInterval[1]){
                        res.back()[1] = max(res.back()[1],newInterval[1]);
                        res.back()[0] = min(res.back()[0],newInterval[0]);
                    }
                    else{
                        res.push_back(newInterval);
                    }
                }
                if (res.back()[1]>=intervals[i][0] && res.back()[0]<intervals[i][1]){
                    res.back()[1] = max(res.back()[1],intervals[i][1]);
                    res.back()[0] = min(res.back()[0],intervals[i][0]);
                }
                else{
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
        

    }
};
