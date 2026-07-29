class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> arr(n,0);
        arr[0] = nums[0];
        for (int i=1;i<n;i++){
            arr[i] = arr[i-1] + nums[i];
        }
        int count = 0;
        int val = max(1,goal);
        for (int k=val;k<=n;k++){
            int j = 0;
            if (k==n){
                if (arr[n-1]==goal) count++;
                break;
            }
            int temp = arr[k-1] - nums[k-1];
            for (int i=k-1;i<n;i++){
                temp += nums[i];
                if (temp==goal) count++;
                temp -= nums[j];
                j++;
            }
        }
        return count;
    }
};