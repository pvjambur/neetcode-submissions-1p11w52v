class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;

        for (auto x : adj[node]){
            if (!vis[x]){
                if (dfs(x, node, adj, vis)) return true;
            }
            else if (x != parent){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; 

        vector<vector<int>> adj(n);
        for (auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> vis(n, false);

        if (dfs(0, -1, adj, vis)) return false; 


        for (int i = 0; i < n; i++){
            if (!vis[i]) return false;
        }

        return true;
    }
};