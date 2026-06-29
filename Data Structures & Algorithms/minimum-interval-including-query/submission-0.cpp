class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         int n = queries.size();
        vector<int> res(n);
       
        sort(intervals.begin(),intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        
        for (int i=0;i<n;i++){
            int num = queries[i];
            int min_int = INT_MAX;
            for (auto &v: intervals){
              if (num>=v[0] && num<=v[1]){
                    min_int =  min(min_int,v[1]-v[0]+1);
                }
            }

            if (min_int==INT_MAX) res[i] = -1;
            else res[i] = min_int;

        }

        return res;
    }
};
