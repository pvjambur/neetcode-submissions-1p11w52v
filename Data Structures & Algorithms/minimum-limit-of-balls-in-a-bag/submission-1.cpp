class Solution {
private:
    bool check(vector<int>& nums, int val, int ops){
        int n = nums.size();
        for (int i=n-1;i>=0;i--){
            if (val>=nums[i]) return true;
            else{
                int temp = nums[i]/val;
                if (nums[i]%val==0) temp--;
                if (temp>ops) return false;
                ops -= temp;
            }

        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int l = 1;
        while (l<=r){
            int mid = (l+r)/2;
            if (check(nums,mid,maxOperations)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
