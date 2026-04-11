class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> res;

    void dfs(string node){
        auto &pq = adj[node];

        while (!pq.empty()){
            string next = pq.top();
            pq.pop();
            dfs(next);

        }
        res.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &v: tickets){
            adj[v[0]].push(v[1]);
        }
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};
