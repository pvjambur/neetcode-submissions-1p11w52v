class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> check;
        for (int i=0;i<nums.size();i++){
            if (check.find(nums[i])!=check.end()) check.erase(nums[i]);
            else check.insert(nums[i]);
        }
        for (int x: check) return x;
    }
};
