class Solution {

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a, const vector<int>& b){
            return (a[0]*a[1])>(b[0]*b[1]);
        });
        int n = envelopes.size();
        vector<int> dp(n,-1);
        dp[n-1] = 1;
        int maxCnt = 1;

        for (int i=n-1;i>=0;i--){
            if (dp[i]!=-1) continue;
            int j = i+1;
            int count = 0;
            vector<int> temp = envelopes[i];
            while (j<n){
                if (envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1] && dp[j]!=-1){
                    count = max(count,dp[j]);
                }
                j++;
            }
            dp[i] = 1 + count;
            maxCnt = max(maxCnt,dp[i]);
        }
        return maxCnt;


    }
};