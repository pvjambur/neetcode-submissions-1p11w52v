class Solution {
private:
    int search(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if (ind>=days.size()) return 0;
        if (dp[ind]!=-1) return dp[ind];

        int op1 = costs[0] + search(ind+1,days,costs,dp);

        int j = ind;
        while (j<days.size() && days[j]<days[ind]+7) j++;
        int op2 = costs[1] + search(j,days,costs,dp);

        j = ind;
        while (j<days.size() && days[j]<days[ind]+30) j++;
        int op3 = costs[2] + search(j,days,costs,dp);
        return dp[ind] = min({op1,op2,op3});  
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return search(0,days,costs,dp);
    }
};