class Solution {
public:
    vector<vector<int>> res;
    void backTrack(int ind, vector<int>& candidates, vector<int>& cur, int target){
        if (target==0){
            res.push_back(cur);
            return;
        }

        if (target<0) return;

        for (int i=ind;i<candidates.size();i++){
            if (i>ind && candidates[i]==candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            backTrack(i+1,candidates,cur,target-candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        backTrack(0,candidates,cur,target);
        return res;
    }
};
