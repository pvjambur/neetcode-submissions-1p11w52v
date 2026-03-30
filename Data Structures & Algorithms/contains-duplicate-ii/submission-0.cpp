class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i=0;i<=k && i<n;i++){
            if (s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
        }
        for (int i=k+1;i<n;i++){
            s.erase(nums[i-k-1]);
            if (s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};