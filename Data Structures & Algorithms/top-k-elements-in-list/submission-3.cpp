class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int x: nums){
            mp[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto &p: mp){
            pq.push({p.second,p.first});

            if (pq.size()>k){
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty()){
            auto [c,x] =  pq.top();
            pq.pop();
            res.push_back(x);
        }

        return res;
    }
};