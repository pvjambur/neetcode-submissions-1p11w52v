class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        int ans = -1, mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>,
                           greater<pair<int,int>>> pq;

            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (auto [v, w] : adj[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt <= mn) {
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};