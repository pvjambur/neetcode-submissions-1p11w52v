class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, first = -1, last = -1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }

        if (l < n && nums[l] == target) first = l;
        else return {-1, -1};

        l = 0, r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m - 1;
        }

        last = r;

        return {first, last};
    }
};