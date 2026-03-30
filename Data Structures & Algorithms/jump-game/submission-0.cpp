class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0;
        int n = nums.size();
        if (n==1) return true;
        int flag=0;
        for (int i=0;i<n;i++){
            if (flag==0){
                maxind = max(maxind,nums[i]+i);
                if (nums[i]==0) flag=1;
            }
            else{
                if (i<=maxind){
                    maxind = max(maxind,i+nums[i]);
                    flag=0;
                }
                else return false;
                if (nums[i]==0) flag=1;
            }
            if (maxind>=n-1) return true;
        }
        return false;
    }
};
