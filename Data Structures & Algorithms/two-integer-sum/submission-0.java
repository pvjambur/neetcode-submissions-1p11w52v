class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> s = new HashMap<>();

        for (int i=0;i<nums.length;i++){
            int x = nums[i];
            int needs = target-x;
            if (s.containsKey(needs)){
                return new int[]{s.get(needs),i};
            }
            s.put(x,i);
        }
        return new int[]{};
        
        
    }
}
