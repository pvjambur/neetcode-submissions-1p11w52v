
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> p(n, 1);
        for (int i = 1; i < n; i++)
            p[i] = (2LL * p[i - 1]) % mod;

        int l = 0, r = n - 1, ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + p[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
