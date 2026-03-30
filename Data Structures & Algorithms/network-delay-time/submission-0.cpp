class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        // build graph
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // min heap: {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto &[next, wt] : adj[node]) {
                if (time + wt < dist[next]) {
                    dist[next] = time + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};