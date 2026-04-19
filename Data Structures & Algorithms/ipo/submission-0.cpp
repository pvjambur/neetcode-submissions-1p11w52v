class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        unordered_map<int,priority_queue<int>> mp;
        int n = profits.size();
        for (int i=0;i<n;i++){
            mp[capital[i]].push(profits[i]);
        }
        while (k--){
            int temp = w;
            while (mp.find(temp)==mp.end()){
                temp--;
            }
            w += mp[temp].top();
            mp[temp].pop();
        }
        return w;

    }
};