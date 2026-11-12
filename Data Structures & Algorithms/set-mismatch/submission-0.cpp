class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        int n = nums.size();

        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int num : nums) {
                if (num == i) {
                    cnt++;
                }
            }

            if (cnt == 0) {
                res[1] = i;
            } else if (cnt == 2) {
                res[0] = i;
            }
        }

        return res;
    }
};