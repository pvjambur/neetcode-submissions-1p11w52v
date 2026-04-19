class Solution {
    public int removeElement(int[] nums, int val) {
        int temp=0;
        int i=0,j=nums.length-1;
        while(i<=j){
            while (nums[j]==val) j--;
            if (nums[i]==val && i<nums.lenght && j>=0){
                nums[i] = nums[j];
                nums[j] = val;
                j--;
            }
            i++;
        }
        return i;
    }
}