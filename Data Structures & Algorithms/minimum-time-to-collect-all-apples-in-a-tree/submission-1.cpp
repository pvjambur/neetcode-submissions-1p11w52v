class Solution {
private:
    int dfs(int ind, vector<vector<int>>& adj, vector<bool>& hasApple, int par){
        int tot_time =0;

        for (int nei: adj[ind]){
            if (nei==par) continue;
            int time = dfs(nei,adj,hasApple,ind);
            if (time>0 || hasApple[nei]) tot_time += time + 2;
        }
        return tot_time;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for (auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return dfs(0,adj,hasApple,-1);
    }
};