class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = INT_MIN;
        int n = nums.size();
        int check=0;
        vector<int> res;
        for (int i=0;i<n;i++){
            if (nums[i]==0){
                check = 1;
                continue;
            }
            else if (prod==INT_MIN){
                prod = 1;
            }
            prod *= nums[i];
        }
        if (prod==INT_MIN) prod=0;
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
