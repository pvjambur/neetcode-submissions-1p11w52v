class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l = 0;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid]==target || l==mid) return l+1;
            else if (target>nums[mid]) l = mid + 1;
            else if (target<nums[mid]) r = mid - 1;
        }
        return -1;
    }
};