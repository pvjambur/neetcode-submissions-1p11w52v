class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int base = 0;

        for (int x : nums)
            if (x == k)
                base++;

        int ans = base;

        for (int v = 1; v <= 50; v++) {
            if (v == k) continue;

            int cur = 0;
            int best = 0;

            for (int x : nums) {
                int val = 0;

                if (x == v) val = 1;
                else if (x == k) val = -1;

                cur = max(val, cur + val);
                best = max(best, cur);
            }

            ans = max(ans, base + best);
        }

        return ans;
    }
};