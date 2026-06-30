class Solution {
private:
    int rob1(int ind, vector<int>& nums, vector<int>& dp, int flag){
        int n = nums.size();
        if (ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        if (ind==n-1 && flag==1) return 0;

        if (ind==0 && flag==1){
            dp[ind] = nums[ind] + rob1(ind+2,nums,dp,flag);
        }
        else if (ind==0 && flag==0){
            dp[ind] = rob1(ind+1,nums,dp,flag);
        }
        else{
            dp[ind] = max(nums[ind] + rob1(ind+2,nums,dp,flag),rob1(ind+1,nums,dp,flag));
        }

        return dp[ind];


        
    }
   
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if (n==1) return nums[0];
       

       vector<int> dp1(n,-1),dp2(n,-1);
       int money = max(rob1(0,nums,dp1,0),rob1(0,nums,dp2,1));
       return money;
       


       
    }
};
