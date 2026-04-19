class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flag=0;
        int max_count = INT_MIN;
        int count = 0;
        for (int i=0;i<nums.size();i++){
            if (flag==0){
                if (nums[i]==0) continue;
                else{
                    flag=1;
                    count++;
                    max_count = max(max_count,count);
                }
            }
            else{
                if (nums[i]==1){
                    count++;
                    max_count = max(max_count,count);
                }
                else{
                    flag=0;
                    max_count = max(max_count,count);
                    count=0;
                }
            }
        }
        return max_count;

    }
};