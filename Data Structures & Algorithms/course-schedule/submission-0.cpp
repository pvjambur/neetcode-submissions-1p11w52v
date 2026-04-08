class Solution {
private:
    bool dfs(int i, vector<bool>& pathVis, vector<bool>& vis, vector<vector<int>>& adj){
        pathVis[i]=true;
        vis[i] = true;
        for (auto x: adj[i]){
            if (!vis[x]){
                if (dfs(x,pathVis,vis,adj)) return true;
            }
            else if (pathVis[x]) return true;
        }
        pathVis[i] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &v: prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        vector<bool> vis(numCourses,false), pathVis(numCourses,false);
        for (int i=0;i<numCourses;i++){
            if (!vis[i]){
                unordered_set<int> s;
                if (dfs(i,pathVis,vis,adj)) return false;
            }
        }
        return true;
        
    }
};
