class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int ind, vector<int>& cur, vector<int>& nums){
        res.push_back(cur);
        int n = nums.size();
        if (ind>=n) return;
        for (int i=ind;i<n;i++){
            cur.push_back(nums[i]);
            backtrack(i+1,cur,nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(0,cur,nums);
        return res;
    }
        
};
