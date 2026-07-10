class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);

        dist[0] = 0;
        int total_cost = 0;

        for (int i=0;i<n;i++){
            int u = -1;

            for (int j=0;j<n;j++){
                if (!vis[j] && (u == -1 || dist[j] < dist[u])){
                    u = j;
                }
            }

            vis[u] = true;
            total_cost += dist[u];

            for (int v=0;v<n;v++){
                if (!vis[v]){
                    int minDist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    dist[v] = min(dist[v],minDist);
                }
            }
        }
        return total_cost;
    }
};
