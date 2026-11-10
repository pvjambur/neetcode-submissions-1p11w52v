class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int suf_sum = 0;
        int n = nums.size();
        for (int x: nums){
            suf_sum += x;
        }
        int pref_sum = 0;
        for (int i=0;i<n;i++){
            suf_sum -= nums[i];
            if (pref_sum==suf_sum) return i;
            pref_sum += nums[i];
        }
        return -1;
    }
};