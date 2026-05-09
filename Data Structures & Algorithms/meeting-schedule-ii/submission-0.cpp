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
        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
            return a.start<b.start;
        });

        priority_queue<int,vector<int>,greater<int>> pq;

        for (auto &m: intervals){
            int s = m.start;
            int e = m.end;

            if (!pq.empty() && s>=pq.top()){
                pq.pop();
            }

            pq.push(e);
        }

        return pq.size();

    }
};
