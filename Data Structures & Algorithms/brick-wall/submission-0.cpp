class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int> mp;
        for (auto &v: wall){
            long long end = 0;
            int m = v.size();
            for (int i=0;i<m;i++){
                if (i!=m-1){
                    end += v[i];
                    mp[end]++;
                }
            }
        }
        int cnt = 0;
        for (auto &p: mp){
            cnt = max(cnt,p.second);
        }
        return wall.size() - cnt;
    }
};