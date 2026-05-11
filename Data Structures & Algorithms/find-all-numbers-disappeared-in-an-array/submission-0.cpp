class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> res;
        int n = nums.size();
        for (int i=1;i<=n;i++){
            if (!s.count(i)) res.push_back(i);
        }
        return res;
    }
};