class Solution {
private:
    int dfs(int child, int par, vector<vector<int>>& adj){
        int max_h = INT_MIN;
        for (int node: adj[child]){
            if (node==par) continue;
            max_h = max(max_h,dfs(node,child,adj));
        }
        return 1 + max_h;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int min_h = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for (int node=0;node<n;node++){
            int height = dfs(node,-1,adj);
            min_h = min(min_h,height);
            mp[height].push_back(node);
        }

        return mp[min_h];
    }
};