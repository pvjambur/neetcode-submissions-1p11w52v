class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> max_h;
        int n = nums.size();
        vector<int> pq_lmao(n,0);
        for (int x: nums){
            max_h.push(x);
        }
        int i=0;
        while (!max_h.empty() && i<n){
            pq_lmao[i++] = max_h.top();
            max_h.pop();
        }
        i=0;
        int j = n-1;
        int k = 0;
        while (i<j){
            nums[k++] = pq_lmao[i];
            i++;
            nums[k++] = pq_lmao[j];
            j--;
        }
    }
};
