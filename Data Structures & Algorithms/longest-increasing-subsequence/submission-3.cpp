class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i=0;i<n;i++){
            if (res.size()==0 || nums[i]>res.back()){
                res.push_back(nums[i]);
                continue;
            }

            if (nums[i]<res.back()){
                int lt = 0;
                while (lt<res.size() && res[lt]<nums[i]){
                    lt++;
                }
                res[lt] = nums[i];
            
            }
           
        }
        return res.size();
    }
};
