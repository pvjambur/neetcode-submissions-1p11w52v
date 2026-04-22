class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto x: nums){
            mp[x]++;
        }
        int count = 0;
        for (auto &[num,amm]: mp){
            if (amm==1) return -1;
            else if (amm==2 || amm==3) count++;
            else if (amm%3==1) count += (((amm-4)/3) + 2);
            else if (amm%3==2) count += ((amm/3) + 1);
            else count+=(amm/3);
        }
        return count;
    }
};