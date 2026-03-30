/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<vector<int>> timings;
        for (Interval &t: intervals){
            timings.push_back({t.start,t.end});
        }
        sort(timings.begin(),timings.end());
        vector<vector<int>> res;
        if (timings.size()<=1) return true;
        res.push_back(timings[0]);
        for (int i=1;i<n;i++){
            if (res.back()[1]>timings[i][0] && res.back()[0]<=timings[i][1]) return false;
            else res.push_back(timings[i]);
        }
        return true;
    }
};
