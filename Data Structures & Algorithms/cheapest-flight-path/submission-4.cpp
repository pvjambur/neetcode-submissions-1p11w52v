class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n,vector<int>(k+2,1e7));

        vector<vector<pair<int,int>>> adj(n);
        for (auto &v: flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,src,k+1});
        dist[src][k+1] = 0;

        while (!pq.empty()){
            int cost = pq.top()[0];
            int node = pq.top()[1];
            int moves = pq.top()[2];
            pq.pop();
            if (dist[node][moves]!=cost) continue;

            if (node==dst) return dist[dst][moves];

            if (moves==0) continue;

            for (auto &p: adj[node]){
                int nei = p.first;
                int ncost = p.second;

                if (ncost + cost < dist[nei][moves-1]){
                    dist[nei][moves-1] = ncost + cost;
                    pq.push({dist[nei][moves-1],nei,moves-1});
                }

            }

        }
        return -1;

    }
};
