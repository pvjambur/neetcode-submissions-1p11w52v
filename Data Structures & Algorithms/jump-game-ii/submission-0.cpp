class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int cur_end=0;
        int jumps=0;
        int n = nums.size();
        if (n==1) return 0;
        for (int i=0;i<n-1;i++){
            farthest = max(farthest,i+nums[i]);

            if (i==cur_end){
                jumps++;
                cur_end = farthest;
            }
        }
        return jumps;
    }
};
