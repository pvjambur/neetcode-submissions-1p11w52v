class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int nei : adj[node]) {

                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Cycle exists
        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};