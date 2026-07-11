class Solution {
private:
    void dfs(int src, int dest, vector<vector<int>>& adj, vector<bool>& vis){
        vis[src] = true;
        if (src==dest) return;

        for (int node: adj[src]){
            if (vis[node]) continue;
            dfs(node,dest,adj,vis);
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for (auto &v: prerequisites){
            adj[v[0]].push_back(v[1]);
        }

        vector<bool> res;

        for (auto &v: queries){
            vector<bool> vis(numCourses,false);

            dfs(v[0],v[1],adj,vis);

            if (vis[v[1]]){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }

        return res;
    }
};