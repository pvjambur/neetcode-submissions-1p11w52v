class Solution {
public:
    vector<vector<int>> res;

    void backTrack(int ind, vector<int>& nums, vector<int>& cur){
        res.push_back(cur);
        for (int i=ind;i<nums.size();i++){
            cur.push_back(nums[i]);
            backTrack(i+1,nums,cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backTrack(0,nums,cur);
        return res;
    }
};
