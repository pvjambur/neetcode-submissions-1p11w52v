class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff=0;
        int tank=0;
        int start=0;
        int total=0;
        for (int i=0;i<gas.size();i++){
            diff = gas[i] - cost[i];
            tank += diff;
            total+=diff;
            if (tank<0){
                tank=0;
                start = (i+1)%(gas.size());

            }
        }
        if (total<0) return -1;
        return start;
    }
};
