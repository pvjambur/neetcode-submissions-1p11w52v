class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<pair<int,int>> s;
        for (int i=0;i<heights.size();i++){
            int x = heights[i];
            while (!s.empty() && s.top().first<=x) s.pop();
            s.push({x,i});
        }
        vector<int> res;
        while (!s.empty()){
            res.push_back(s.top().second);
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};