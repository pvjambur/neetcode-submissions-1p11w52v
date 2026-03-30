class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;
        int i=0,j=0;
        int n = nums.size();
        while (j<n){
            if (nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
        return i+1;
    }
};