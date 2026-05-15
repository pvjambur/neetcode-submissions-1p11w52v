class Solution {
public:

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        auto cmp = [](pair<int,int>& a,pair<int,int>& b){
            if (a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        int n = nums.size();
        for (int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        vector<int> res(n,0);

        while(k--){
            auto [x,y] = pq.top();
            pq.pop();
            x = x*multiplier;
            pq.push({x,y});
        }

        while (!pq.empty()){
            auto [x,y] = pq.top();
            res[y] = x;
            pq.pop();
        }

        return res;
    }
};