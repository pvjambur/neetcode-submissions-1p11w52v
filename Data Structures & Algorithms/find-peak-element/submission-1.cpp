class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int,int>> q;
        q.push({0,n-1});

        while (!q.empty()){
            auto [l,r] = q.front();
            q.pop();
            if (l>r) continue;
            int mid = (l+r)/2;
            int left = INT_MIN, right = INT_MIN;
            if (mid!=0) left = nums[mid-1];
            if (mid!=n-1) right = nums[mid+1];

            if (left<nums[mid] && nums[mid]>right) return mid;
            q.push({l,mid-1});
            q.push({mid+1,r});

        }
        return 0;

    }
};