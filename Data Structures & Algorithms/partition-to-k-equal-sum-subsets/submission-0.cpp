class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& bucket, int idx, int target, int k) {
        if (idx == nums.size())
            return true;

        for (int i = 0; i < k; i++) {
            if (bucket[i] + nums[idx] > target)
                continue;

            if (i > 0 && bucket[i] == bucket[i - 1])
                continue;

            bucket[i] += nums[idx];

            if (dfs(nums, bucket, idx + 1, target, k))
                return true;

            bucket[i] -= nums[idx];

            if (bucket[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % k)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> bucket(k, 0);

        return dfs(nums, bucket, 0, target, k);
    }
};