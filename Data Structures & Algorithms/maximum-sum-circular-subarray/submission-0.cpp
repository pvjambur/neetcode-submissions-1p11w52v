class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int cur_max=0;
        int min_sum = nums[0];
        int cur_min=0;
        int total=0;
        for (int i=0;i<n;i++){
            cur_max = max(nums[i],cur_max+nums[i]);
            max_sum = max(max_sum,cur_max);
            cur_min = min(nums[i],cur_min+nums[i]);
            min_sum = min(min_sum,cur_min);
            total+=nums[i];
        }
        if (max_sum<0) return max_sum;

        return max(max_sum,total-min_sum);
    }
};