class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (int y: arr){
            pq.push({abs(y-x),y});
        }
        vector<int> res;
        while (!pq.empty() && k--){
            auto [dis,num] = pq.top();
            pq.pop();
            res.push_back(num);
        }
        sort(res.begin(),res.end());
        return res;
    }
};