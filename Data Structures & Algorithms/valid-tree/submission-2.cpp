class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                int node = q.front();
                q.pop();
                int al_vis = 0;
                for (int nei: adj[node]){
                    if (vis[nei]){
                        al_vis++;
                        if (al_vis==2) return false;
                        continue;
                    }
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        for (int x: vis){
            if (x==0) return false;
        }
        return true;
    }
};
