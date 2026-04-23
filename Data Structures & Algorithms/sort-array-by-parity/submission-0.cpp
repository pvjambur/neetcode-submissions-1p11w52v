class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        sort(nums.begin(),nums.end());
        int i = 0, j = n-1;
        for (int x: nums){
            if (x%2==0) res[i++] = x;
            else res[j--] = x;
        }
        return res;
    }
};