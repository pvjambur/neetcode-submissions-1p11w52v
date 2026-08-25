class Solution {
public:
    vector<vector<int>> res;
    void bt(int ind, vector<int>& nums, vector<int>& cur){
        int n = nums.size();
        res.push_back(cur);
        if (ind==n) return;
        for (int i=ind;i<n;i++){
            cur.push_back(nums[i]);
            bt(i+1,nums,cur);
            cur.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        bt(0,nums,cur);
        return res;
    }
};
