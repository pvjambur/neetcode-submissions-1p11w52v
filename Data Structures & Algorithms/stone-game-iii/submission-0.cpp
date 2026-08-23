class Solution {
private:
    int pick(int ind, vector<int>& stoneValue, vector<int>& dp){
        int n = stoneValue.size();
        if (ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        int limit = min(n,ind+3);
        int val = INT_MIN;
        int cur = 0;
        for (int i=ind;i<limit;i++){
            cur += stoneValue[i];
            val = max(val,cur - pick(i+1,stoneValue,dp));
        }
        return dp[ind] = val;

    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,-1);
        int val = pick(0,stoneValue,dp);
        if (val>0){
            return "Alice";
        }
        else if (val<0){
            return "Bob";
        }
        return "Tie";
    }
};