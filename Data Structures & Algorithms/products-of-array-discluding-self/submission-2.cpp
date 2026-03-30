class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        int check=0;
        vector<int> res;
        for (int i=0;i<n;i++){
            if (nums[i]==0){
                check++;
                continue;
            }
            prod *= nums[i];
        }
        if (check>=2) prod = 0;
        for (int i=0;i<n;i++){
            if (nums[i]==0){
                res.push_back((int)(prod));
                continue;
            }
            if (check==1){
                res.push_back(0);
                continue;
            }
            res.push_back((int)(prod/nums[i]));
        }
        return res;
    }
};
