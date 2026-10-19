class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        for (auto &v: edges){
            indeg[v[1]]++;
        }
        int team = -1;
        for (int i=0;i<n;i++){
            if (indeg[i]==0){
                if (team!=-1) return -1;
                team = i;
            }
        }
        return team;
    }
};
