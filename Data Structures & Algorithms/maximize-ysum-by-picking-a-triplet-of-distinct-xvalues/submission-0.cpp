class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++){
            int nx = x[i];
            int ny = y[i];
            if (mp.count(nx)){
                mp[nx] = max(mp[nx],ny);
            }
            else{
                mp[nx] = ny;
            }
        }
        if (mp.size()<3) return -1;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto &[nx,ny]: mp){
            pq.push(ny);
            if (pq.size()>3){
                pq.pop();
            }
        }
        int tot = 0;
        while (!pq.empty()){
            tot += pq.top();
            pq.pop();
        }
        return tot;
    }
};