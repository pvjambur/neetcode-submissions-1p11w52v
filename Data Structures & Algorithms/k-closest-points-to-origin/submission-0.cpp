class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> res;
        priority_queue<pair<int,vector<int>>> pq;
        for (auto &c: points){
            int x = c[0];
            int y = c[1];
            int dist = x*x + y*y;
            pq.push({dist,c});
            while (pq.size()>k) pq.pop();   
        }

        while (!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
