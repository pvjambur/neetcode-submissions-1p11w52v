class Solution {
private:
    int dfs(int child, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int tot_time = 0;

        for (auto &node: adj[child]){
            if (node==parent) continue;

            int childTime = dfs(node,child,adj,hasApple);

            if (childTime>0 || hasApple[node]) tot_time += childTime + 2;
        }
        return tot_time;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};