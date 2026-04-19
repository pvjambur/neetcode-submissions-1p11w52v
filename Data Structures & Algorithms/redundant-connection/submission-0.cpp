class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> s;
        for (auto &v: edges){
            bool f1 = (s.find(v[0])!=s.end());
            bool f2 = (s.find(v[1])!=s.end());

            if (f1 && f2) return v;
            else{
                s.insert(v[0]);
                s.insert(v[1]);
            }
        }
        return {-1,-1};
    }
};
