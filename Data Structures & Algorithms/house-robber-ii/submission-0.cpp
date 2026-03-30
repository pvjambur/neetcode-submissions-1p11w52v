class Solution {
private:
    int pick(int ind, int selectF, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if (ind>=n) return 0;
        if (ind==n-1 && selectF==1) return 0;
        if (dp[ind][selectF]!=-1) return dp[ind][selectF];
        if (ind==0){
            dp[ind][selectF] = max(nums[0] + pick(2,1,nums,dp),pick(1,0,nums,dp));
        }
        else{
            dp[ind][selectF] = max(nums[ind] + pick(ind+2,selectF,nums,dp), pick(ind+1,selectF,nums,dp));
        }
        return dp[ind][selectF];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return pick(0,0,nums,dp);
    }
};
