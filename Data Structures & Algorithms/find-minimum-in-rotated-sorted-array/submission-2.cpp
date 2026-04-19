class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[l]>nums[r]){
                if (l!=mid) l = mid;
                else l = mid+1;
            }
            else if (nums[l]<nums[r]){
                r = mid;
            }
            else break;
        }
        return nums[l];
    }
};
