class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,pair<int,int>> mp;
        for (int i=0;i<trust.size();i++){
            mp[trust[i][1]].first++;
            mp[trust[i][0]].second++;
        }
        for (auto &x: mp){
            if (x.second.second==0) return x.first;
        }
        return -1;
    }
};