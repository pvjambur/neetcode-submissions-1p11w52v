class Solution {
public:
    vector<vector<int>> res;
    void backTrack(int ind, vector<int>& nums){
        if (ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for (int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            backTrack(ind+1,nums);
            swap(nums[ind],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(0,nums);
        return res;
    }
};
