class Solution {
private:
    int steps(int ind, vector<int>& cost, vector<int>& dp){
        if (ind>=dp.size()) return 0;
        if (dp[ind]!=-1) return dp[ind];
        dp[ind] = cost[ind] + min(steps(ind+1,cost,dp),steps(ind+2,cost,dp));
        return dp[ind];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(steps(0,cost,dp),steps(1,cost,dp));
        
    }
};
