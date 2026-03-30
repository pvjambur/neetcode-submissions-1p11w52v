class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int incre = 0;
        int n = nums.size();
        if (n==1) return true;
        
        for (int i=1;i<n;i++){
            if (nums[i]==nums[i-1]) continue;
            else if (nums[i]>nums[i-1]){
                if (incre==0) incre=1;
                else if (incre==2) return false;
            }
            else{
                if (incre==0) incre=2;
                else if (incre==1) return false;
            }
        }
        return true;
    }
};