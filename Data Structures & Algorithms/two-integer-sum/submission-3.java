class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<>();

        for (int i=0;i<nums.length;i++){
            int x = nums[i];
            int needs = target - nums[i];

            if (mp.containsKey(needs)){
                return new int[]{mp.get(needs),i};
            }
            mp.put(x,i);
        }
        return new int[]{};
        
        
    }
}
