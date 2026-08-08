class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &v: times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,1e8);
        dist[k] = 0;

        while(!pq.empty()){
            auto [wt,nd] = pq.top();
            pq.pop();

            if (wt>dist[nd]) continue;
            for (auto &v: adj[nd]){
                int nwt = v.second;
                int nei = v.first;
                if (dist[nd] + nwt < dist[nei]){
                    dist[nei] = dist[nd] + nwt;
                    pq.push({dist[nei],nei});
                }
            }
        }

        int mx_time = INT_MIN;
        for (int i=1;i<=n;i++){
            mx_time = max(mx_time,dist[i]);
        }
        
        if (mx_time==1e8) return -1;
        return mx_time;
    }
};
