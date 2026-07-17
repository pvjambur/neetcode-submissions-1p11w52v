class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int w = nums[0];
        int x = nums[1];
        int y = nums[n-2];
        int z = nums[n-1];

        return ((z*y) - (x*w));
    }
};