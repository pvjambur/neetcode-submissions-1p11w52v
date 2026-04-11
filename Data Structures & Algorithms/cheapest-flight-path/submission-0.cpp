class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &v: flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        queue<pair<int,int>> q;

        q.push({src,0});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        int count = 0;
        while (!q.empty() && count<=k){
            int s = q.size();
            vector<int> temp = dist;

            while (s--){
                auto [node,cost] = q.front();
                q.pop();

                for (auto &[nei,price]: adj[node]){
                    if (cost + price < temp[nei]){
                        temp[nei] = cost + price;
                        q.push({nei,temp[nei]});
                    }
                }
            }

            dist = temp;    
            count++;
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];

    }
};
