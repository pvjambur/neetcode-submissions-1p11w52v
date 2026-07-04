class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k-1+maxPts) return 1.0;

        vector<double> dp(n+1,0.0);
        dp[0]=1.0;
        double windowSum=1.0;
        double result=0.0;

        for(int x=1;x<=n;x++){
            dp[x]=windowSum/maxPts;
            if(x<k) windowSum+=dp[x];
            else result+=dp[x];
            if(x-maxPts>=0 && x-maxPts<k) windowSum-=dp[x-maxPts];
        }

        return result;
    }
};