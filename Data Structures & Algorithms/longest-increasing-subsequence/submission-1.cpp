class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_sz = 1;
        priority_queue<pair<int,int>> pq;
        for (int i=n-1;i>=0;i--){
           
            int temp_sz = 1;
            priority_queue<pair<int,int>> temp = pq;
            while (!temp.empty() && nums[i]<temp.top().first){
                int cur_sz = 1 + temp.top().second;
                temp.pop();
                temp_sz = max(temp_sz,cur_sz);
            }
            pq.push({nums[i],temp_sz});
            max_sz = max(max_sz,temp_sz);
        }
        return max_sz;
    }
};
