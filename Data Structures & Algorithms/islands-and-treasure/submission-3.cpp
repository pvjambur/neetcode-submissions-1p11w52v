class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int dist = 0;
    queue<pair<int,int>> q;
    int m = grid.size();
    int n = grid[0].size();

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j]==0) q.push({i,j});
        }
    }
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()){
        int sz = q.size();
        for (int i=0;i<sz;i++){
            auto [x,y] = q.front();
            q.pop();
            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]==-1 || dist+1>=grid[nx][ny]) continue;
                grid[nx][ny] = dist+1;
                q.push({nx,ny});
            }
        }
        dist++;
    }
    return;
    }
};
