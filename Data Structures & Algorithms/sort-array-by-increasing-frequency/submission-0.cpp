class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x: nums){
            mp[x]++;
        }
        vector<priority_queue<int>> arr(101);
        for (auto &[x,y]: mp){
            arr[y].push(x);
        }
        vector<int> res;
        for (int i=1;i<101;i++){
            if (arr[i].size()==0) continue;
            while (!arr[i].empty()){
                int temp = arr[i].top();
                arr[i].pop();
                for (int k=0;k<i;k++){
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};