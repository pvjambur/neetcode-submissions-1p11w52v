class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        while (l<r){
            int mid = (l+r)/2;
            if (nums[mid]>nums[r]) l = mid+1;
            else r = mid;
        }
        int k = l;
        l=k;
        r = k+n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid%n]<target) l = mid+1;
            else if (nums[mid%n]>target) r = mid-1;
            else return mid%n;
        }
        return -1;
    }
};
