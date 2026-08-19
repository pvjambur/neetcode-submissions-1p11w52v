class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int cur_time = 0;
        double tot_wait = 0.0;
        for (auto &v: customers){
            cur_time = max(cur_time,v[0]);
            cur_time += v[1];
            tot_wait += (double)(cur_time - v[0]);
        }
        int n = customers.size();
        return tot_wait/n;
    }
};