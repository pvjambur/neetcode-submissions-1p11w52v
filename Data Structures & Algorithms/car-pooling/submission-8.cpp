class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<vector<int>> res;
        for (int i=0;i<n;i++){
            int temp = trips[i][0];
            trips[i][0] = trips[i][1];
            trips[i][1] = trips[i][2];
            trips[i][2] = temp;
        }
        sort(trips.begin(),trips.end());
        int cap = trips[0][2];
        res.push_back(trips[0]);
        if (cap>capacity) return false;
        for (int i=1;i<n;i++){
            if ((res.back()[1]>trips[i][0] && res.back()[0]<trips[i][0]) || (res.back()[0]>trips[i][0] && res.back()[0]<trips[i][0]) || (res.back()[0]<trips[i][0] && res.back()[1]>trips[i][1])){
                res.back()[1] = max(res.back()[1],trips[i][1]);
                res.back()[0] = min(res.back()[0],trips[i][0]);
                cap+=trips[i][2];
            }
            else{
                res.push_back(trips[i]);
                cap = trips[i][2];
            }
            if (cap>capacity) return false;
        }
        return true;
    }
};