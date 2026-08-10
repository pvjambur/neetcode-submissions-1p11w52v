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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start(n,0),end(n,0);
        for (int i=0;i<n;i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i=0,j=0;
        int rooms = 0,mx=0;
        while (i<n && j<n){
            if (start[i]<end[j]){
                rooms++;
                mx = max(rooms,mx);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }

        return mx;
    }
};
