class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj;

    double dfs(string src, string dst, unordered_set<string>& vis) {
        if (!adj.count(src) || !adj.count(dst)) return -1.0;
        if (src == dst) return 1.0;

        vis.insert(src);

        for (auto& [v, w] : adj[src]) {
            if (vis.count(v)) continue;

            double res = dfs(v, dst, vis);
            if (res != -1.0)
                return w * res;
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> ans;

        for (auto& q : queries) {
            unordered_set<string> vis;
            ans.push_back(dfs(q[0], q[1], vis));
        }

        return ans;
    }
};