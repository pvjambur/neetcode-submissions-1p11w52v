class Solution {
private:
    void dfs(int ind, vector<vector<int>>& adj, vector<bool>& visited){
        visited[ind] = true;
        for (auto x: adj[ind]){
            if (!visited[x]){
                dfs(x,adj,visited);
            }
        }
    }


public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count = 0;
        vector<bool> visited(n,false);
        for (int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};
