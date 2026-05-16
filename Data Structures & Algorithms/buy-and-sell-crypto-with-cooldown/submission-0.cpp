class Solution {
private:
    int solve(int ind, int canBuy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if (ind>=n) return 0;

        if (dp[ind][canBuy]!=-1) return dp[ind][canBuy];

        if (canBuy){
            int buy = -prices[ind] + solve(ind+1,0,prices,dp);
            int hold = solve(ind+1,1,prices,dp);
            dp[ind][canBuy] = max(buy,hold);
        }
        else{
            int sell = prices[ind] + solve(ind+2,1,prices,dp);
            int hold = solve(ind+1,0,prices,dp);
            dp[ind][canBuy] = max(sell,hold);
        }

        return dp[ind][canBuy];
        
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        // 1 -> should buy
        // 0-> should sell

        return solve(0,1,prices,dp);
    }
};
