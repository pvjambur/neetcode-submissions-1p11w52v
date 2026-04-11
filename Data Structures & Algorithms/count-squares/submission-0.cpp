class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0],y = point[1];
        mp[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0],y = point[1];
        int res = 0;
        for (auto &[ny,freq]: mp[x]){
            if (ny==y) continue;
            int d = ny - y;

            res += freq*mp[x+d][ny] * mp[x+d][y];
            res += freq*mp[x-d][ny]*mp[x-d][y];
        }
        return res;
    }
};
