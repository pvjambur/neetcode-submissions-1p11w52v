class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int left_dom = -1,right_dom = -1;
        unordered_map<int,int> left,right;
        int n = nums.size();

        for (int x: nums){
            right[x]++;
        }
        
        for (int i=0;i<n-1;i++){
            left[nums[i]]++;
            right[nums[i]]--;

            if (2*left[nums[i]]>(i+1) && 2*right[nums[i]]>(n-i-1)) return i;
        }
        return -1;
    }
};

