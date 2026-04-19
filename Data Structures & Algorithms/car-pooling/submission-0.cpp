class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int cap = trips[0][0];
        if (cap>capacity) return false;
        for (int i=1;i<n;i++){
            if (trips[i][1]<trips[i-1][2] || trips[i][1]>=trips[i-1][1]){
                cap+=trips[i][0];
            }
            else{
                cap = trips[i][0];
            }
            if (cap>capacity) return false;
        }
        return true;
    }
};