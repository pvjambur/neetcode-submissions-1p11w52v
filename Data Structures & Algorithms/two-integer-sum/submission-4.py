class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        n = len(nums);

        for i in range(0,n):
            x = nums[i];
            needs = target - nums[i];

            if needs in mp:
                return [mp[needs],i]

            mp[x] = i;
        
        return []