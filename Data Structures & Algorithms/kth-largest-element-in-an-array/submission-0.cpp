class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num: nums){
            pq.push(num);
            while (pq.size()>k) pq.pop();
        }
        if (pq.empty()) return -1;
        return pq.top();
    }
};
