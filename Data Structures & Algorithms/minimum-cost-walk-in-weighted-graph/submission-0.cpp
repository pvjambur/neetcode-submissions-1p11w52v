class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build connected components
        for (auto& e : edges)
            unite(e[0], e[1]);

        // AND of all edge weights in each component
        vector<int> cost(n, -1);

        for (auto& e : edges) {
            int root = find(e[0]);
            cost[root] &= e[2];
        }

        vector<int> ans;

        for (auto& q : query) {
            int u = q[0], v = q[1];

            if (find(u) != find(v))
                ans.push_back(-1);
            else
                ans.push_back(cost[find(u)]);
        }

        return ans;
    }
};