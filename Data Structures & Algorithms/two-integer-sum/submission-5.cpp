class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++){
            if (mp.find(target-nums[i])!=mp.end()) continue;
            mp[target-nums[i]] = i;
        }

        for (int i=0;i<nums.size();i++){
            if (mp.find(nums[i])!=mp.end() && i!=mp[nums[i]]){
                return {min(i,mp[nums[i]]),max(i,mp[nums[i]])};
            }
        }
        return {};
    }
};
