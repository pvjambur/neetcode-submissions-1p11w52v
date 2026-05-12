class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_set<int>> mp;
        mp[0].insert(0);
        int x = 0, y = 0;
        for (char c: path){
            if (c=='N') y++;
            else if (c=='E') x++;
            else if (c=='S') y--;
            else if (c=='W') x--;
            if (mp.find(x)!=mp.end()){
                if (mp[x].count(y)) return true;
            }
            mp[x].insert(y);
        }
        return false;
    }
};