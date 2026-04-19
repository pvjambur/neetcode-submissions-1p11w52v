class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        int cap = trips[0][0];
        vector<vector<int>> res;
        sort(trips.begin(),trips.end());
        res.push_back(trips[0]);
        if (cap>capacity) return false;
        for (int i=1;i<n;i++){
            if ((res.back()[2]>trips[i][1] && res.back()[1]<trips[i][1]) || (res.back()[1]>trips[i][1] && res.back()[2]<trips[i][2]) || (res.back()[1]<trips[i][1] && res.back()[2]>trips[i][2])){
                res.back()[2] = max(res.back()[2],trips[i][2]);
                res.back()[1] = min(res.back()[1],trips[i][1]);
                cap+=trips[i][0];
            }
            else{
                res.push_back(trips[i]);
                cap = trips[i][0];
            }
            if (cap>capacity) return false;
        }
        return true;
    }
};