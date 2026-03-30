class Solution {
public:
    vector<vector<int>> res;
    void backTrack(int ind, vector<int>& nums, vector<int>& cur, int target){
        if (target==0) res.push_back(cur);
        if (target<2) return;
        for (int i=ind;i<nums.size();i++){
            cur.push_back(nums[i]);
            backTrack(i,nums,cur,target-nums[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backTrack(0,nums,cur,target);
        return res;
    }
};
