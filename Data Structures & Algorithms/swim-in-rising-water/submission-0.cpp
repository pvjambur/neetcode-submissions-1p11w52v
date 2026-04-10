class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>
        > pq;

        vector<vector<int>> vis(n,vector<int>(n,0));

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        pq.push({grid[0][0],{0,0,}});

        while (!pq.empty()){
            auto [time,p] = pq.top();
            auto [x,y] = p;
            pq.pop();

            if (vis[x][y]) continue;
            vis[x][y] = 1;

            if (x==n-1 && y==n-1) return time;

            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]){
                    int newTime = max(time,grid[nx][ny]);
                    pq.push({newTime,{nx,ny}});
                }
            }
        }
        return -1;



    }
};
