class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        for (int i=0;i<nums.size()-1;i++){
            if (flag<2 && nums[i]<=nums[i+1]) continue;
            else if (flag==0 & nums[i]>nums[i+1]){
                flag++;
            }
            else return false;
        }
        if (flag==1){
            if (nums[0]>=nums[nums.size()-1]) return true;
            else return false;
        }
        return true;

    }
};