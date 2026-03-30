class Solution {
private:
    int pick(int ind, vector<int>& nums, vector<int>& dp){
        if (ind>=nums.size()) return 0;
        if (dp[ind]!=-1) return dp[ind];
        dp[ind] = max((nums[ind]+pick(ind+2,nums,dp)),pick(ind+1,nums,dp));
        return dp[ind];
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1,-1);
        return pick(0,nums,dp);
    }
};
