class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& grid, vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n){
                    if (heights[nx][ny]>=heights[x][y] && grid[nx][ny]==false){
                        grid[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));
        queue<pair<int,int>> p;
        queue<pair<int,int>> a;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i==0 || j==0){
                    p.push({i,j});
                    pacific[i][j]=true;
                }
                if (i==m-1 || j==n-1){
                    a.push({i,j});
                    atlantic[i][j]=true;
                }
            }
        }

        bfs(p,pacific,heights);
        bfs(a,atlantic,heights);

        vector<vector<int>> res;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;


    }
};
