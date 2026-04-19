class Solution {
int decode(int ind, string& s, vector<int>& dp){
    if (ind>=s.size() || s[ind]!=0) return 1;
    if (s[ind]=='0') return 0;
    if (dp[ind]!=-1) return dp[ind];
    int d1 = s[ind]-'0';
    int d2 = s[ind+1]-'0';
    int num = d1*10 + d2;
    if (num<=26){
        return dp[ind] = decode(ind+1,s,dp) + decode(ind+2,s,dp);
    }
    return dp[ind] = decode(ind+1,s,dp);
}

public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0]=='0') return 0;
        if (n==1) return 1;
        
        vector<int> dp(n+1,-1);
        return decode(0,s,dp);
    }
};
