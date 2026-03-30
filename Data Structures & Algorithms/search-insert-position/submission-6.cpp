class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l = 0;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid]==target) return mid;
            else if (l==r){
                if (target<nums[l]) return l;
                else return l+1;
            }
            else if (target>nums[mid]) l++;
            else if (target<nums[mid]) r--;
        }
        return -1;
    }
};