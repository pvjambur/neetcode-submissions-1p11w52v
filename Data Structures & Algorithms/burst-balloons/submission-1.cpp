class Solution {
private:
    int burst(int l, int r, vector<int>& nums, vector<vector<int>>& dp){
        if (l+1==r) return 0;
        if (dp[l][r]!=-1) return dp[l][r];
        int max_value = 0;
        for (int i=l+1;i<r;i++){
            int cur_value = 0;
            
            cur_value = nums[l]*nums[i]*nums[r];
            max_value = max(max_value,cur_value + burst(l,i,nums,dp) + burst(i,r,nums,dp));
       
        }
        return dp[l][r] = max_value;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return burst(0,n+1,nums,dp);
    }
};
