class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int swi=0;
        int tot_cost=0;
        int n = gas.size();
        for (int i=0;i<n;i++){
            tot_cost += gas[i] - cost[i];
            if (tot_cost>0 && tot_cost-gas[i]+cost[i]<=0) swi=i;
        }
        if (tot_cost<0) return -1;
        return swi;
    }
};
