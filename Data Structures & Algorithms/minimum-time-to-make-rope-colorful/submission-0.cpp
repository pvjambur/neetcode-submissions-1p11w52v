class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i=0;
        int res = 0;
        while (i<n){
            int j = i;
            char val = colors[i];
            int max_val = INT_MIN;
            int tot_val = 0;
            while (j<n && colors[j]==val){
                tot_val += neededTime[j];
                max_val = max(max_val,neededTime[j]);
                j++;
            }
            res += tot_val - max_val;
            i = j;
        }
        return res;
    }
};