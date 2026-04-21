class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x: nums){
            mp[x]++;
        }
        vector<int> res;
        int temp = floor((nums.size())/3);
        for (auto &[num,count]: mp){
            if (count>temp) res.push_back(num);
        }
        return res;
    }
};