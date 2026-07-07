class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> mx;
        deque<int> q;
        for (int x: nums){
            mx.push(x);
        }

        while (!mx.empty()){
            q.push_back(mx.top());
            mx.pop();
        }

        int n = nums.size();
        int i=0;
        bool mn_val = true;
        while (i<n){
            if (mn_val){
                mn_val = false;
                nums[i] = q.front();
                q.pop_front();
            }
            else{
                mn_val = true;
                nums[i] = q.back();
                q.pop_back();
            }
            i++;
        }
    }
};
