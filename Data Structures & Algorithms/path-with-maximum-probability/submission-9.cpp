class Solution {


public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        int m = edges.size();
        for (int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});

        while (!pq.empty()){
            auto [curprob,node] = pq.top();
            pq.pop();

            if (node==end_node){
                return curprob;
            }

            if (curprob < prob[node]) continue;

            for (auto &p: adj[node]){
                double newprob = curprob * p.second;

                if (newprob>prob[p.first]){
                    pq.push({newprob, p.first});
                    prob[p.first] = newprob;
                }
                
            }
        }

        return 0.0;
    }
};