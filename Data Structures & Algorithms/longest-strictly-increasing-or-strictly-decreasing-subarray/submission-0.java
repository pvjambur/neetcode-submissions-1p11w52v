class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int len = Integer.MIN_VALUE;
        int n = nums.length;
        if (n==1) return 1;

        int i=1,j=0;
        while (i<n){
            while (i<n && nums[i-1]==nums[i]){
                j=i;
                i++;
            }
            len = Math.max(len,1);
            while (i<n && nums[i-1]<nums[i]){
                i++;
            }
            len = Math.max(len,i-j);
            j=i-1;
            while (i<n && nums[i-1]>nums[i]){
                i++;
            }
            len = Math.max(len,i-j);
            j=i-1;
        }
        return len;
    }
}