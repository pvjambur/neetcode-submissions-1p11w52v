class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int val = floor(n/2);
        for (auto &[x,y]: mp){
            if (y>val) return x;
        }
        return -1;
    }
};