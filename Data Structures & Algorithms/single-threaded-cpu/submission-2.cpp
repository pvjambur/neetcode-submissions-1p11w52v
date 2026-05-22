class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> ntasks(n,vector<int>(3,0));
        
        for (int i=0;i<n;i++){
            ntasks[i][0] = tasks[i][0];
            ntasks[i][1] = tasks[i][1];
            ntasks[i][2] = i;
        }
        sort(ntasks.begin(),ntasks.end(),[](const vector<int>& a, const vector<int>& b){
            if (a[0]==b[0]){
                return a[1]<=b[1];
            }
            return a[0]<b[0];
        });
        auto cmp = [](const vector<int>&a, const vector<int>& b){
            if (a[1]==b[1]){
                return a[2]>=b[2];
            }
            return a[1]>b[1];
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);

        vector<int> res;
        long long wind = ntasks[0][0] + ntasks[0][1];
        res.push_back(ntasks[0][2]);
        int i=1;
        while (i<n){
            while (i<n && ntasks[i][0]<=wind){
                pq.push(ntasks[i]);
                i++;
            }
            if (!pq.empty()){
                res.push_back(pq.top()[2]);
                wind += pq.top()[1];
                pq.pop();
            }
            else{
                wind = ntasks[i][0];
            }
            
        }

        while (!pq.empty()){
            res.push_back(pq.top()[2]);
            pq.pop();
        }
        return res;

    }
};