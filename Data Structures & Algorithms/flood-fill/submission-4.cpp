class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        int temp = image[sr][sc];
        if(temp == color) return image;
        image[sr][sc] = color;
        q.push({sr,sc});
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (auto &d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==temp){
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;

    }
};