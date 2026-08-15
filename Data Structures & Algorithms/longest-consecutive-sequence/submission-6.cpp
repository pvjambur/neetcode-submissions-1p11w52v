class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for (int x: nums){
            if (!s.count(x-1)){
                int cur =x;
                int len = 0;
                while (s.count(cur)){
                    cur++;
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
